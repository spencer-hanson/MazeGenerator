//============================================================================
// Name        : RatMaze.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MazeGen.h"
#include <stdlib.h>

using namespace std;



int main() {

	MazeGen maze (30);
	maze.printMazeToFile();
	
	return 0;
}



