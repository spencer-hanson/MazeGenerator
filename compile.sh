#!/bin/bash
g++ src/* -o Debug/RatMaze
echo "Run?"
read RUN
if [ $RUN == 'y' ]
then
	./Debug/RatMaze
fi
