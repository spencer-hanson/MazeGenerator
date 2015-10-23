//============================================================================
// Name        : RatMaze.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MazeGen.h"
#include "Maze.h"

using namespace std;



int main(int argc, char *argv[]) {

	int size = stoi(argv[1]);
	MazeGen gen_maze (size);
//	gen_maze.printMaze();
//	gen_maze.printMazeToFile("maze.txt");

//	gen_maze.printMaze();
//	Maze maze ("maze.txt");
//	maze.printMaze();
	return 0;
}



