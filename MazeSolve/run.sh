#!/bin/bash
make clean
make
echo "Run?"
read PAUSE
./bin/MazeSolve
