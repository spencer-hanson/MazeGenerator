# GeneticRatMaze
###There are 3 main parts to the Genetic Maze:
##MazeGen
..*Generates a maze given size of maze, can save to file and/or print to console
....*Written in C++
..*MazeGUI
....*Displays a window of the maze, read in from a generated maze file
....*Reads from local 'maze.txt'
....*Takes args on the path to the MazeGen executable, the size of maze to generate, and size of the cells
....*The size of the cells determines the "resolution" of each wall/pathway, in pixels
..*MazeSolve
....*In development!


Compiling Guide:
- MazeGen
+ For Linux/OSX:
- run compile.sh in the MazeGen directory, will create an executable in 'Debug'
+ For Windows:
- No auto compile script yet! Take a look at compile.sh for guidance if you want to anyways!
- MazeGUI
+ For Linux/OSX:
- run compile.sh in the MazeGUI directory, will create jarfile in current directory, 'MazeGUI.jar'
+ For Windows:
- No auto compile script yet! Take a look at compile.sh for guidance if you want to anyways!
- MazeSolve
+ In development!

Run Guide:
- MazeGen - A program written to generate mazes of specified sizes
+ For Linux/OSX, default executable name is 'MazeGen'
+ For Windows, default executable name is 'MazeGen.exe'
+ Used like so: <executable> <size of maze> [-o (optional output flag) <output filename>] [-p (optional force print to console)]
+ Run <executable> to see examples
- MazeGUI - A GUI written in java to view the generated Maze
+ Default jar-file name is 'MazeGUI.jar'
+ Used like so: java -jar <jarfile> <GenMaze executable> <Maze Size> <Maze Cell Size>
+ Click on the Generated Maze to re-generate it!
- MazeSolve
+ In development!


