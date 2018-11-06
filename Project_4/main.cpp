#include "MazeSolver.h"
#include <iostream>

int main(int argc, char* argv[]) {
	MazeSolver solverA("inputA.txt");
	MazeSolver solverB("inputB.txt");
	MazeSolver solverC("inputC.txt");
	MazeSolver solverD("inputD.txt");

	if (solverA.mazeIsReady()) {
		// solve mazes
		solverA.solveMaze();
		solverB.solveMaze();
		solverC.solveMaze();
		solverD.solveMaze();

		// print solutions
		solverA.printSolution();
		solverB.printSolution();
		solverC.printSolution();
		solverD.printSolution();
	}

	return 0;
}
