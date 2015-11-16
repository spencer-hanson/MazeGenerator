#Author: Spencer Hanson
OBJS = debug/Gen.o debug/MazeCell.o debug/MazeGen.o
PROG = bin/MazeGen
CPPFLAGS = -std=c++11
CC = g++

###########

mazegen: $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(PROG)
debug/MazeCell.o: src/MazeCell.h src/MazeConstants.h
	$(CC) $(CPPFLAGS) -c src/MazeCell.cpp -o debug/MazeCell.o
debug/MazeGen.o: src/MazeGen.h src/MazeCell.h src/MazeConstants.h
	$(CC) $(CPPFLAGS) -c src/MazeGen.cpp -o debug/MazeGen.o
debug/Gen.o: src/MazeGen.h
	$(CC) $(CPPFLAGS) -c src/Gen.cpp -o debug/Gen.o
clean:
	$(RM) debug/*
	$(RM) $(PROG)
