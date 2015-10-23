/*
 * MazeCell.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: m4trixsh4d0w
 */

#include "MazeCell.h"
#include "MazeConstants.h"
#include <iostream>

MazeCell::MazeCell() {
	pos_y = -1;
	pos_x = -1;
	visited = false;
	southWall = true; //wall is there, not broken
	northWall = true;
	eastWall = true;
	westWall = true;
	center = MazeConstant::PATH_CHAR;
}

MazeCell::~MazeCell() {

}

void MazeCell::setMazeCenterChar(char ch) {
	this->center = ch;
}

char* MazeCell::printCell() {
	char mid = MazeConstant::PATH_CHAR;
	if (visited) {
		mid = center;
	} else {
		mid = 'M'; //only if cell hasn't been visited, every cell should have been visited
	}

	char top = MazeConstant::PATH_CHAR;
	if (northWall) {
		top = MazeConstant::WALL_CHAR;
	}

	char btm = MazeConstant::PATH_CHAR;
	if (southWall) {
		btm = MazeConstant::WALL_CHAR;
	}

	char lft = MazeConstant::PATH_CHAR;
	if (westWall) {
		lft = MazeConstant::WALL_CHAR;
	}

	char rht = MazeConstant::PATH_CHAR;
	if (eastWall) {
		rht = MazeConstant::WALL_CHAR;
	}

	char crn = MazeConstant::WALL_CHAR; //Corner

	/*
	 * {crn}{top}{crn}
	 * {lft}{mid}{rht}
	 * {crn}{btm}{crn}
	 */

	char cell[9] = {crn, top, crn, lft, mid, rht, crn, btm, crn };
	char *ptr = cell;

	return ptr;

}

MazeCell::DIRECTION MazeCell::getOppositeWall(MazeCell::DIRECTION dir) {
	switch (dir) {
	case NORTH:
		return SOUTH;
		break;
	case SOUTH:
		return NORTH;
		break;
	case EAST:
		return WEST;
		break;
	case WEST:
		return EAST;
		break;
	default:
		return NORTH;
	}
}

void MazeCell::breakWall(DIRECTION direction) {
	switch (direction) {
	case NORTH:
		northWall = false;
		break;
	case SOUTH:
		southWall = false;
		break;
	case EAST:
		eastWall = false;
		break;
	case WEST:
		westWall = false;
		break;
	}
}

void MazeCell::printInfo(bool tab) {
	if(tab) {
		std::cout << "\tPos: (" << pos_x << ", " << pos_y << ")" << std::endl;
		std::cout << "\tVisited: " << visited << std::endl;
	} else {
		std::cout << "Pos: (" << pos_x << ", " << pos_y << ")" << std::endl;
		std::cout << "Visited: " << visited << std::endl;
	}
}

bool MazeCell::getVisited() {
	return visited;
}

int MazeCell::getPosX() {
	return pos_x;
}

int MazeCell::getPosY() {
	return pos_y;
}

void MazeCell::setVisited(bool visited) {
	this->visited = visited;
}

void MazeCell::setPosX(int pos_x) {
	this->pos_x = pos_x;
}

void MazeCell::setPosY(int pos_y) {
	this->pos_y = pos_y;
}
