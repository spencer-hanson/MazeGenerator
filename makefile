#Author: Spencer Hanson
MAZEGEN_DIR = MazeGen
MAZEGEN_OBJS = Gen.o MazeCell.o MazeGen.o
MAZEGEN_PROG = MazeGen
CPPFLAGS = -std=c++11
CC = g++

mazegen: MazeGen/Debug/*.o
	cd $(MAZEGEN_DIR)/Debug
	$(CC) $(CPPFLAGS)  $(MAZEGEN_OBJS) -o $(MAZEGEN_PROG)
MazeGen/src/MazeCell.o: MazeCell.h MazeConstants.h
	$(CC) $(CPPFLAGS) -c $(MAZEGEN_DIR)/src/MazeCell.cpp -o $(MAZEGEN_DIR)/Debug/MazeCell.o
MazeGen/src/MazeGen.o: MazeGen.h MazeCell.h MazeConstants.h
	$(CC)  $(CPPFLAGS) -c $(MAZEGEN_DIR)/src/MazeGen.cpp -o $(MAZEGEN_DIR)/Debug/MazeGen.o
MazeGen/src/Gen.o: MazeGen.h
	$(CC) $(CPPFLAGS) -c $(MAZEGEN_DIR)/src/Gen.cpp -o ($MAZEGEN_DIR)/Debug/Gen.o
clean-all:
	$(RM) $(MAZEGEN_DIR)/Debug/*
