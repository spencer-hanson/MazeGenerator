/*
 * MazeCell.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: m4trixsh4d0w
 */

#include "MazeCell.h"

MazeCell::MazeCell() {
	pos_y = -1;
	pos_x = -1;
	visited = false;
	southWall = true; //wall is there, not broken
	northWall = true;
	eastWall = true;
	westWall = true;
	center = '*';
}

MazeCell::~MazeCell() {

}


void MazeCell::setMazeCenterChar(char ch) {
	this->center = ch;
}
char* MazeCell::printCell() {

/*
	char mid = '%';
	if(visited) {
		mid = '*';
	} else {
		mid = '&';
	}

	char top = '-';
	if(northWall) {
		top = '#';
	}

	char btm = '-';
	if(southWall) {
		btm = '#';
	}

	char lft = '|';
	if(westWall) {
		lft = '#';
	}

	char rht = '|';
	if(eastWall) {
		rht = '#';
	}

	/*

	char mid = '%';
		if(visited) {
			mid = '*';
		} else {
			mid = 'M';
		}

		char top = 'T';
		if(northWall) {
			top = '#';
		}

		char btm = 'B';
		if(southWall) {
			btm = '#';
		}

		char lft = 'L';
		if(westWall) {
			lft = '#';
		}

		char rht = 'R';
		if(eastWall) {
			rht = '#';
		}
*/
		char mid = '%';
			if(visited) {
				mid = center;
			} else {
				mid = 'M';
			}

			char top = '*';
			if(northWall) {
				top = '#';
			}

			char btm = '*';
			if(southWall) {
				btm = '#';
			}

			char lft = '*';
			if(westWall) {
				lft = '#';
			}

			char rht = '*';
			if(eastWall) {
				rht = '#';
			}

	char cell[5] = {top, lft, mid, rht, btm };
	char *ptr = cell;

	return ptr;

}

MazeCell::DIRECTION MazeCell::getOppositeWall(MazeCell::DIRECTION dir) {
	switch(dir) {
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
	switch(direction) {
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
/*
 * bool getVisited();
	int getPosX();
	int getPosY();
	void setVisited(bool);
	void setPosX(int);
	void setPosY(int);
 */
