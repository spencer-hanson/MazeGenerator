#!/bin/bash
if [ ! -d "Debug" ]; then
	mkdir Debug
fi
echo "Compiling..."
g++ -g -std=c++11 src/* -o Debug/MazeGen
echo "Run?"
read RUN
if [ $RUN == 'y' -o $RUN == 'Y' ]; then
	if [ ! -z "$1" ]; then
		./Debug/MazeGen $1
	else
		./Debug/MazeGen 8
	fi
fi
