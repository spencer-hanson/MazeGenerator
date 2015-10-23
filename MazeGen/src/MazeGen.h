/*
 * MazeGen.h
 *
 *  Created on: Sep 6, 2015
 *      Author: m4trixsh4d0w
 */
#include "MazeCell.h"
#include <string>
#include <vector>
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
		MazeCell::DIRECTION direction[4] = { MazeCell::NONE, MazeCell::NONE, MazeCell::NONE, MazeCell::NONE };
		int count = -8;
	};
	std::vector<std::vector<MazeCell>> cells;
	int* getRandom(int);
	NeighborCellGroup getNeighborCells(MazeCell *);
	void genMaze(MazeCell*, MazeCell::DIRECTION);

};


#endif /* MAZEGEN_H_ */

