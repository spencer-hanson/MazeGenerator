################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Maze.cpp \
../src/MazeCell.cpp \
../src/MazeGen.cpp \
../src/RatMaze.cpp 

OBJS += \
./src/Maze.o \
./src/MazeCell.o \
./src/MazeGen.o \
./src/RatMaze.o 

CPP_DEPS += \
./src/Maze.d \
./src/MazeCell.d \
./src/MazeGen.d \
./src/RatMaze.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


