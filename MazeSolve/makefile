#Author: Spencer Hanson
OBJS = debug/Breeder.o debug/Fitness.o debug/Gene.o debug/GeneStats.o debug/GenoType.o debug/Incubator.o debug/Maze.o debug/Mutator.o debug/Solver.o
PROG = bin/MazeSolve
CPPFLAGS = -std=c++11
CC = g++

########
mazesolve: $(OBJS)
	$(CC) $(CPPFLGS) $(OBJS) -o $(PROG)

debug/Breeder.o: src/Breeder.h
	$(CC) $(CPPFLAGS) -c src/Breeder.cpp -o debug/Breeder.o

debug/Fitness.o: src/Fitness.h
	$(CC) $(CPPFLAGS) -c src/Fitness.cpp -o debug/Fitness.o
debug/Gene.o: src/Gene.h
	$(CC) $(CPPFLAGS) -c src/Gene.cpp -o debug/Gene.o

debug/GeneStats.o: src/GeneStats.h
	$(CC) $(CPPFLAGS) -c src/GeneStats.cpp -o debug/GeneStats.o

debug/GenoType.o: src/GenoType.h
	$(CC) $(CPPFLAGS) -c src/GenoType.cpp -o debug/GenoType.o

debug/Incubator.o: src/Incubator.h
	$(CC) $(CPPFLAGS) -c src/Incubator.cpp -o debug/Incubator.o

debug/Maze.o: src/Maze.h
	$(CC) $(CPPFLAGS) -c src/Maze.cpp -o debug/Maze.o

debug/Mutator.o: src/Mutator.h
	$(CC) $(CPPFLAGS) -c src/Mutator.cpp -o debug/Mutator.o

debug/Solver.o: src/Maze.h
	$(CC) $(CPPFLAGS) -c src/Solver.cpp -o debug/Solver.o

clean:
	$(RM) debug/*
	$(RM) $(PROG)
