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



int main() {

	MazeGen gen_maze (420);
	gen_maze.printMazeToFile("maze.txt");
	//gen_maze.printMaze();
	
	Maze maze ("maze.txt");
	maze.printMaze();
	return 0;
}



