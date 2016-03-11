/*
 * MazeGen.cpp
 *      Author: Spencer Hanson
 */
#include <iostream>
#include <stdlib.h>
#include "MazeGen.h"
#include "MazeCell.h"
#include "MazeConstants.h"
#include <fstream>
#include <string>
#include <vector>

const int MAX_CELLS = MazeConstant::MAX_CELLS;

MazeGen::MazeGen(int size) {

	srand((unsigned)time(0)); //set up random

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
	for(int i = 0;i<size;i++) {
		this->cells.push_back(std::vector<MazeCell>(size, MazeCell()));
	}


	//Initialize all the cells in the array with a cell pointer
	MazeCell *currentCell;

	for(int x = 0;x<size;x++) {
		for(int y = 0;y<size;y++) {
			currentCell = &cells.at(x).at(y);
			currentCell->setPosX(x);
			currentCell->setPosY(y);
		}
	}

	int startx = rand() % size; //random start x val
	int starty = rand() % size; //random start y val

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
	default:
		std::cout << "Error :(" << std::endl;
		break;
	}
	genMaze(&cells[startx][starty], dir); //Generate maze with center 'startx','starty' from direction 'dir'

	//Create Start
	cells[startx][0].setMazeCenterChar(MazeConstant::START_CHAR);
	//Create End
	cells[starty][size-1].setMazeCenterChar(MazeConstant::END_CHAR);
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
	}

	if(cell->getPosX() >= size-1) { //cell is on left edge of maze
		east = false;
	}

	if(cell->getPosY() < 1) { //top row cell of maze
		north = false;
	}

	if(cell->getPosY() >= size-1) { //bottom row cell of maze
		south = false;
	}



	//Add directions to list, increment after each addition
	if(east) { neighbors.direction[count++] = MazeCell::EAST;  }
	if(west) { neighbors.direction[count++] = MazeCell::WEST;  }
	if(south){ neighbors.direction[count++] = MazeCell::SOUTH; }
	if(north){ neighbors.direction[count++] = MazeCell::NORTH; }
	neighbors.count = count;

	return neighbors;
}

 std::vector<int> MazeGen::getRandom(int num_size) { //Populate array with random numbers 0-<size-1>, with no repeats
        //int* array = new int[size];
        std::vector<int> array (num_size, -1);

        int tmp = num_size;
        int tmp2 = 0;

        while(tmp > 0) {
            tmp2 = rand() % num_size;
            if(array[tmp2] == -1) {
                array[tmp2] = tmp--;
                array[tmp2]--;
            }
        }

        return array;
    }

void MazeGen::genMaze(MazeCell* currentCell, MazeCell::DIRECTION fromDir) {


	NeighborCellGroup neighbors = getNeighborCells(currentCell); //Group of cells
	std::vector<int> order = getRandom(neighbors.count); //order that you visit cells

	currentCell->breakWall(fromDir); //break the wall between where you started and where you are from
	currentCell->setVisited(true); //don't visit this cell again

	MazeCell::DIRECTION currentDirection; //Direction to iterate into
	MazeCell* nextCell; //pointer to the next cell object, randomly chosen

	#ifdef DEBUG
	currentCell->printInfo(false);
	std::cout << "Count: " << neighbors.count << std::endl;
	#endif

	for(int i = 0;i<neighbors.count;i++) {
		currentDirection = neighbors.direction[order[i]];
		if(currentDirection != fromDir) {
			switch(currentDirection) {
			case MazeCell::NORTH:
				nextCell = &cells.at(currentCell->getPosX()).at(currentCell->getPosY()-1);
				break;
			case MazeCell::SOUTH:
				nextCell = &cells.at(currentCell->getPosX()).at(currentCell->getPosY()+1);
				break;
			case MazeCell::EAST:
				nextCell = &cells.at(currentCell->getPosX()+1).at(currentCell->getPosY());
				break;
			case MazeCell::WEST:
				nextCell = &cells.at(currentCell->getPosX()-1).at(currentCell->getPosY());
				break;
			default:
				std::cout << "We have a problemo" << std::endl;
				break;
			}

			#ifdef DEBUG
				std::cout << "\t-NextCell-" << std::endl;
				nextCell->printInfo(true);
				std::cout << "\tCount: " << neighbors.count << std::endl;
				std::cout << "\t=NextCell=" << std::endl;
			#endif

			if(!(nextCell->getVisited())) {
				currentCell->breakWall(currentDirection); //break the entrance to the next cell
				genMaze(nextCell, MazeCell::getOppositeWall(currentDirection));
			}
		}
	}
}

void MazeGen::printMaze() {
	std::vector<std::vector<char>> maze;
	maze = getMaze();

	for(int y = 0;y<size*3;y++) {
		for(int x = 0;x<size*3;x++) {
			std::cout << maze[x][y];
		}
		std::cout << "\n";
	}
}

std::vector<std::vector<char>> MazeGen::getMaze() { //put 3x3 maze cell object into 2d array
		MazeCell* currentCell;

		std::vector<std::vector<char>> maze (size*3, std::vector<char>(size*3));
//		maze = new char*[size*3];

		int offsetx = 0;
		int offsety = 0;
/*
		for(int i = 0;i<size*3;i++) { //initialize array
			maze[i] = new char[size*3];
		}
*/
		for(int y = 0;y<size;y++) { //through all 'y'

			for(int x = 0;x<size;x++) { //through all 'x'


                //Calculate offset, sets 0th element back, otherwise as placed
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


				currentCell = &cells.at(x).at(y);
				char* cell = currentCell->printCell();
				int k = 0;
				//Loop through cell chars 3x3
				for(int i = 0;i<3;i++) {
					for(int j = 0;j<3;j++) {
						/*
                        * Cell at index*3 (to account for cell size being 3x larger)
						* plus j (the x index of the current cell)
						* plus the offset * x (to account for the cell wall overlap)
						*/
						int index_x = (x*3) + j + (offsetx*x);
						int index_y = (y*3) + i + (offsety*y);

						maze[index_x][index_y] = cell[k]; //set char array equal to character in maze
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
	std::vector<std::vector<char>> maze;
	maze = getMaze();

	for(int y = 0;y<size*3;y++) { //Maze cell is 3x3 so entire maze is 3 times as large
			for(int x = 0;x<size*3;x++) {
				file << maze[x][y];
			}

			file << "\n";
		}
    file.close();
}


