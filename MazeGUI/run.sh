#!/bin/bash
if [ ! -z "$1" ]; then
	if [ ! -z "$2" ]; then
		java -jar MazeGUI.jar ./MazeGen $1 $2
	else
		java -jar MazeGUI.jar ./MazeGen $1 1
	fi
else
	java -jar MazeGUI.jar ./MazeGen 64 1
fi
