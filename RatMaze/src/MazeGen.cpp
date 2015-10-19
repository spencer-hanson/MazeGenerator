/*
 * MazeGen.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: m4trixsh4d0w
 */
#include <iostream>
#include <stdlib.h>
#include "MazeGen.h"
#include "MazeCell.h"
#include <fstream>
#include <string>

const int MAX_CELLS = 1024;
MazeCell cells[MAX_CELLS][MAX_CELLS];

MazeGen::MazeGen(int size) {
	srand((unsigned)time(0));

	if(size < 4) {//Minimum size is 4x4
		size = 4;
	}

	if(size*9 > MAX_CELLS-1) {//Max cell limiter
		size = (MAX_CELLS/9)-1;
	}

	if(size % 2 != 0) { //Maze generation works best if maze isan even number
		size++;
	}

	this->size = size;
	MazeCell *currentCell;

	for(int x = 0;x<size;x++) {
		for(int y = 0;y<size;y++) {
			currentCell = &cells[x][y];
			currentCell->setPosX(x);
			currentCell->setPosY(y);
		}
	}

	int startx = rand() % size - 1;
	int starty = rand() % size - 1;
	MazeCell::DIRECTION dir;
	switch(rand() % 4) {
	case 0:
		dir = MazeCell::EAST;
		break;
	case 1:
		dir = MazeCell::WEST;
		break;
	case 2:
		dir = MazeCell::SOUTH;
		break;
	case 3:
		dir = MazeCell::NORTH;
		break;
	}
	genMaze(&cells[startx][starty], dir);
	//Create Start
	cells[startx][0].setMazeCenterChar('S');
	//Create End
	cells[starty][size-1].setMazeCenterChar('E');
	//cells[startx][starty].setMazeCenterChar('%');
}

MazeGen::~MazeGen() {

}

MazeGen::NeighborCellGroup MazeGen::getNeighborCells(MazeCell* cell) {

	NeighborCellGroup neighbors;

	int count = 0; //count of cells in neighbors

	bool north = true; //is there a neighbor north?
	bool south = true; //true until proven false
	bool east = true;
	bool west = true;

	if(cell->getPosX() < 1) { //cell is on right edge
		west = false;
	} else if(cell->getPosX() > size-2) { //cell is on left edge
		east = false;
	}

	if(cell->getPosY() < 1) { //top row cell
		north = false;
	} else if(cell->getPosY() > size-2) { //bottom row cell
		south = false;
	}

	if(east) { neighbors.direction[count++] = MazeCell::EAST; }
	if(west) { neighbors.direction[count++] = MazeCell::WEST; }
	if(south){ neighbors.direction[count++] = MazeCell::SOUTH; }
	if(north){ neighbors.direction[count++] = MazeCell::NORTH; }
	neighbors.count = count;

	return neighbors;
}

int* MazeGen::getRandom(int size) {
	int* array = new int[size];
	int count = 0;
	int num;
	bool inArray = false;

	for(int i = 0;i<size;i++) {
		array[i] = -1;
	}

	while(count < size) {
	
		num = rand() % size;
		inArray = false;
		
		for(int i  = 0;i<size;i++) {
				if(num == array[i]) {
					inArray = true;
				}
			}
			
			if(!inArray) {
			*(array + count) = num;
			count++;
		}
	}

	return array;
}

void MazeGen::genMaze(MazeCell* currentCell, MazeCell::DIRECTION fromDir) {
	NeighborCellGroup neighbors = getNeighborCells(currentCell);
	int* order = getRandom(neighbors.count);

	currentCell->breakWall(fromDir);
	currentCell->setVisited(true);

	MazeCell::DIRECTION currentDirection;
	MazeCell* nextCell;

	for(int i = 0;i<neighbors.count;i++) {
		currentDirection = neighbors.direction[order[i]];
		if(currentDirection != fromDir) {
			switch(currentDirection) {
			case MazeCell::NORTH:
				nextCell = &cells[currentCell->getPosX()][currentCell->getPosY()-1];
				break;
			case MazeCell::SOUTH:
				nextCell = &cells[currentCell->getPosX()][currentCell->getPosY()+1];
				break;
			case MazeCell::EAST:
				nextCell = &cells[currentCell->getPosX()+1][currentCell->getPosY()];
				break;
			case MazeCell::WEST:
				nextCell = &cells[currentCell->getPosX()-1][currentCell->getPosY()];
				break;
			}

			if(!(nextCell->getVisited())) {
				currentCell->breakWall(currentDirection);
				genMaze(nextCell, MazeCell::getOppositeWall(currentDirection));
			}
		}
	}
}


void MazeGen::printMaze() {
	MazeCell* currentCell;
	std::cout << "-----------" << std::endl;
	char** maze;
	maze = getMaze();

	for(int y = 0;y<size*3;y++) {
		for(int x = 0;x<size*3;x++) {
			std::cout << maze[x][y];
		}
		std::cout << std::endl;
	}
}

char** MazeGen::getMaze() {
		MazeCell* currentCell;

		char** maze = 0;
		maze = new char*[size*3];

		int offsetx = 0;
		int offsety = 0;

		for(int i = 0;i<size*3;i++) {
			maze[i] = new char[size*3];
		}

		for(int y = 0;y<size;y++) {

			for(int x = 0;x<size;x++) {

				if(x != 0) {
					offsetx = 0;
				} else {
					offsetx = -1;
				}

				if(y != 0) {
					offsety = 0;
				} else {
					offsety = -1;
				}


				currentCell = &cells[x][y];
				char* cell = currentCell->printCell();
				int k = 0;
				for(int i = 0;i<3;i++) {
					for(int j = 0;j<3;j++) {
						if((i == 0 && j == 0) || (i == 0 && j == 2) || (i == 2 && j == 0) || (i == 2 && j == 2)) { //corners
							maze[(x*3)+j + (offsetx*x)][(y*3)+i + (offsety*y)] = '#';
						} else {
							maze[(x*3)+j + (offsetx*x)][(y*3)+i + (offsety*y)] = cell[k];
							k++;
						}
					}
				}

			}

		}
		return maze;
}

void MazeGen::printMazeToFile(std::string filename) {

	std::ofstream file;
	file.open (filename);
	char** maze;
	maze = getMaze();

	for(int y = 0;y<size*3;y++) {
			for(int x = 0;x<size*3;x++) {
				file << maze[x][y];
			}

			file << "\n";
		}
file.close();

}


