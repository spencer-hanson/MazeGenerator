#!/bin/bash
g++ -std=c++11 src/* -o Debug/RatMaze
echo "Run?"
read RUN
if [ $RUN == 'y' ]
then
	./Debug/RatMaze
fi
