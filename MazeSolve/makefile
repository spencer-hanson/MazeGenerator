#Author: Spencer Hanson
OBJS = debug/GenoType.o debug/Maze.o debug/Mouse.o debug/Solver.o
PROG = bin/MazeSolve
CPPFLAGS = -std=c++11
CC = g++

########
mazesolve: $(OBJS)
	$(CC) $(CPPFLGS) $(OBJS) -o $(PROG)
debug/GenoType.o: src/GenoType.h
	$(CC) $(CPPFLAGS) -c src/GenoType.cpp -o debug/GenoType.o
debug/Maze.o: src/Maze.h
	$(CC) $(CPPFLAGS) -c src/Maze.cpp -o debug/Maze.o
debug/Mouse.o: src/Mouse.h
	$(CC) $(CPPFLAGS) -c src/Mouse.cpp -o debug/Mouse.o
debug/Solver.o: src/Maze.h src/Mouse.h
	$(CC) $(CPPFLAGS) -c src/Solver.cpp -o debug/Solver.o
clean:
	$(RM) debug/*
	$(RM) $(PROG)
