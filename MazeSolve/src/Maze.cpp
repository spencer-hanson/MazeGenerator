/*
 * Maze.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: m4trixsh4d0w
 */
#include "Maze.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Maze::Maze(string filename) {
	int lineY = 0;

	string line = "";
	ifstream file;
	file.open(filename);

	int start_x = -1;
	int start_y = -1;
	int end_x = -1;
	int end_y = -1;

	if(file) {
		while(!file.eof()) {
			getline(file, line);
			for(int i = 0;i<line.length();i++) {
				maze_array[lineY][i] = line.at(i);
				if(line.at(i) == 'S') {
					start_x = i;
					start_y = lineY;
				} else if(line.at(i) == 'E') {
					end_x = i;
					end_y = lineY;
				}
			}
			lineY++;
		}
	}

	this->start_loc.index_x = start_x;
	this->start_loc.index_y = start_y;
	this->end_loc.index_x = end_x;
	this->end_loc.index_y = end_y;
	this->size_y = lineY;
}

void Maze::printMaze() {

	for(int i = 0;i<size_y;i++) {
		std::cout << maze_array[i] << std::endl;
	}
	
	std::cout << "Start at: (" << start_loc.index_x << ", " << start_loc.index_y << ")" << std::endl;
	std::cout << "End at: (" << end_loc.index_x << ", " << end_loc.index_y << ")" << std::endl;
}

Maze::~Maze() { }



