#!/bin/bash
if [ ! -d "Debug" ]; then
	mkdir Debug
fi
echo "Compiling..."
g++ -g -std=c++11 src/* -o Debug/MazeSolve
echo "Run?"
read RUN
if [ $RUN == 'y' -o $RUN == 'Y' ]; then
	./Debug/MazeSolve
fi
