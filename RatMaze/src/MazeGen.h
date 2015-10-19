/*
 * MazeGen.h
 *
 *  Created on: Sep 6, 2015
 *      Author: m4trixsh4d0w
 */
#include "MazeCell.h"
#include <string>
#ifndef MAZEGEN_H_
#define MAZEGEN_H_

class MazeGen {
public:

	MazeGen(int);
	virtual ~MazeGen();
	void printMaze();
	void printMazeToFile(std::string);

private:
	int size;
	char** getMaze();
	struct NeighborCellGroup {
		MazeCell::DIRECTION direction[4] = { MazeCell::NORTH, MazeCell::NORTH, MazeCell::NORTH, MazeCell::NORTH };
		int count = 0;
	};

	int* getRandom(int);
	NeighborCellGroup getNeighborCells(MazeCell *);
	void genMaze(MazeCell*, MazeCell::DIRECTION);

};


#endif /* MAZEGEN_H_ */
