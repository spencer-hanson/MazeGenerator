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

	MazeGen gen_maze (2);
	gen_maze.printMaze();
//	gen_maze.printMazeToFile("maze.txt");

	//gen_maze.printMaze();
	
//	Maze maze ("maze.txt");
//	maze.printMaze();
	return 0;
}



