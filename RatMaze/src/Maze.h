/*
 * Maze.h
 *
 *  Created on: Sep 6, 2015
 *      Author: m4trixsh4d0w
 */
#include <iostream>
#include <string>
#ifndef MAZE_H_
#define MAZE_H_
class Maze {
private:
	char maze_array[1024][1024];
	int size_y;
	struct Location {
		int index_x;
		int index_y;
	} start_loc, end_loc;

public:
	Maze(std::string);
	virtual ~Maze();
	void printMaze();
};




#endif /* MAZE_H_ */
