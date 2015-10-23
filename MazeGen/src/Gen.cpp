//============================================================================
// Name        : RatMaze.cpp
// Author      : Spencer Hanson
// Version     : 1.0
// Copyright   : GNU GPL
// Description : Generates a maze using given parameters
//============================================================================

#include <iostream>
#include <string>
#include "MazeGen.h"

using namespace std;


void usage(char *name) {
	cout << "Incorrect Usage!" << endl;
	cout << "Usage: " << name << " <size> [-o <output.txt>] [-p]" << endl;
	cout << "Examples: \n" << name << " 8 -o maze.txt -p" << endl;
	cout << "This will generate a 8x8 maze, store it in maze.txt and print it out" << endl;
	cout << name << " 16" << endl;
	cout << "This will generate a 16x16 maze, and print it out to the screen" << endl;
}

int main(int argc, char *argv[]) {

	bool printOut = true;
	bool writeToFile = false;
	string fileName = "maze.txt";

	if(argc < 2) {
		usage(argv[0]);
		return 0;
	}

	int size = 0;

	try {
		size = stoi(argv[1]);
	} catch(...) {
		cout << "Syntax Error!" << endl;
		usage(argv[0]);
		return 0;
	}

	if(argc > 2) { //Oh boy we have -o or -p or both
		string arg2 = argv[2];
		if(arg2 == "-o") {
			if(!(argc > 3)) { //didn't give enough args for -o, make sure they didn't forget the file
				usage(argv[0]);
				return 0;
			} else {
				string arg3 = argv[3];
				printOut = false;
				writeToFile = true;
				fileName = arg3;
			}
		}

		if(argc > 4) { //They want to print it out and save to file
			string arg4 = argv[4];
			if(arg4 == "-p") {
				printOut = true;
			}
		}
	}


	MazeGen gen_maze (size);

	if(printOut) {
		gen_maze.printMaze();
	}

	if(writeToFile) {
		gen_maze.printMazeToFile(fileName);
	}

	return 0;
}
