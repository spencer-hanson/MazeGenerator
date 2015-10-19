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
#include "MazeConstants.h"
#include <fstream>
#include <string>

const int MAX_CELLS = MazeConstant::MAX_CELLS;
MazeCell cells[MAX_CELLS/3+1][MAX_CELLS/3+1]; //Only need 1/3 as many cells, each cell is 3x3

MazeGen::MazeGen(int size) {
	srand((unsigned)time(0));

	if(size < 4) { //Minimum size is 4x4
		size = 4;
	}

	if(size*3 > MAX_CELLS-1) {//Max cell limiter
		size = (MAX_CELLS/3)-1; //Maximum size
	}

	if(size % 2 != 0) { //Maze generation works best if maze is an even number
		size++;
	}

	this->size = size;

	//Initialize all the cells in the array with a cell pointer
	MazeCell *currentCell;
	for(int x = 0;x<size;x++) {
		for(int y = 0;y<size;y++) {
			currentCell = &cells[x][y];
			currentCell->setPosX(x);
			currentCell->setPosY(y);
		}
	}

	int startx = rand() % size - 1; //random start x val
	int starty = rand() % size - 1; //random start y val

	MazeCell::DIRECTION dir;

	switch(rand() % 4) { //randomly pick a direction to "start from"
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
	genMaze(&cells[startx][starty], dir); //Generate maze with center 'startx','starty' from direction 'dir'
	//Create Start
	cells[startx][0].setMazeCenterChar(MazeConstant::START_CHAR);
	//Create End
	cells[starty][size-1].setMazeCenterChar(MazeConstant::END_CHAR);
	//cells[startx][starty].setMazeCenterChar('%'); //Set the starting cell center to '%'
}

MazeGen::~MazeGen() { }

MazeGen::NeighborCellGroup MazeGen::getNeighborCells(MazeCell* cell) {

	NeighborCellGroup neighbors;

	int count = 0; //count of cells in neighbors

	bool north = true; //is there a neighbor <north>?
	bool south = true; //true until proven false
	bool east = true;
	bool west = true;

	if(cell->getPosX() < 1) { //cell is on right edge of maze
		west = false;
	} else if(cell->getPosX() > size-2) { //cell is on left edge of maze
		east = false;
	}

	if(cell->getPosY() < 1) { //top row cell of maze
		north = false;
	} else if(cell->getPosY() > size-2) { //bottom row cell of maze
		south = false;
	}

	//Add directions to list, increment after each addition
	if(east) { neighbors.direction[count++] = MazeCell::EAST; }
	if(west) { neighbors.direction[count++] = MazeCell::WEST; }
	if(south){ neighbors.direction[count++] = MazeCell::SOUTH; }
	if(north){ neighbors.direction[count++] = MazeCell::NORTH; }
	neighbors.count = count;

	return neighbors;
}
//TODO Make this more efficient (Okay for now, but wouldn't work too well with large numbers)
int* MazeGen::getRandom(int size) { //Populate array with random numbers 0-<size>, with no repeats

	int* array = new int[size];
	int count = 0;
	int num;
	bool inArray = false;

	for(int i = 0;i<size;i++) {
		array[i] = -1;
	}

	while(count < size) { //keep going as long as there are numbers to be generated
		num = rand() % size;
		inArray = false;
		
		for(int i  = 0;i<size;i++) { //Check if generated number is in array
				if(num == array[i]) {
					inArray = true;
				}
			}
			
			if(!inArray) {
				*(array + count) = num; //set the current array index to the generated number
				count++; //increase the array index counter
		}
	}

	return array;
}

void MazeGen::genMaze(MazeCell* currentCell, MazeCell::DIRECTION fromDir) {

	NeighborCellGroup neighbors = getNeighborCells(currentCell); //Group of cells
	int* order = getRandom(neighbors.count); //order that you visit cells

	currentCell->breakWall(fromDir); //break the wall between where you started and where you are from
	currentCell->setVisited(true); //don't visit this cell again

	MazeCell::DIRECTION currentDirection; //Direction to iterate into
	MazeCell* nextCell; //pointer to the next cell object, randomly chosen

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
	char** maze;
	maze = getMaze();

	for(int y = 0;y<size*3;y++) {
		for(int x = 0;x<size*3;x++) {
			std::cout << maze[x][y];
		}
		std::cout << std::endl;
	}
}

char** MazeGen::getMaze() { //put 3x3 maze cell object into 2d array
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
				//Loop through cell chars 3x3
				for(int i = 0;i<3;i++) {
					for(int j = 0;j<3;j++) {
						int index_x = (x*3)+j + (offsetx*x);
						/*Cell at index*3 (to account for cell size being 3x larger)
						* plus j (the x index of the current cell)
						* plus the offset * x (to account for the cell wall overlap)
						*/
						int index_y = (y*3)+i + (offsety*y);

						maze[index_x][index_y] = cell[k];
						k++;
					}
				}

			}

		}
		return maze;
}

void MazeGen::printMazeToFile(std::string filename) {

	std::ofstream file;
	file.open(filename);
	char** maze;
	maze = getMaze();

	for(int y = 0;y<size*3;y++) { //MazeCell is 3x3 so 3 times as large
			for(int x = 0;x<size*3;x++) {
				file << maze[x][y];
			}

			file << "\n";
		}
file.close();

}


