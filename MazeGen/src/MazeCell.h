/*
 * MazeCell.h
 *
 *  Created on: Sep 6, 2015
 *      Author: m4trixsh4d0w
 */

#ifndef MAZECELL_H_
#define MAZECELL_H_
#include <string>

class MazeCell {
	int pos_x;
	int pos_y;
	char center;
	bool visited;
	bool northWall;
	bool southWall;
	bool eastWall;
	bool westWall;
public:
	enum DIRECTION { NORTH, SOUTH, EAST, WEST, NONE };
	void setMazeCenterChar(char);
	void breakWall(DIRECTION);
	char* printCell();
	static DIRECTION getOppositeWall(DIRECTION);
	bool getVisited();
	int getPosX();
	int getPosY();
	void setVisited(bool);
	void setPosX(int);
	void setPosY(int);
	void printInfo(bool);
	MazeCell();
	virtual ~MazeCell();
};

#endif /* MAZECELL_H_ */
