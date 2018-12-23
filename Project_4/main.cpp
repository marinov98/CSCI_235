#include "MazeSolver.h"
#include <iostream>

int main(int argc, char* argv[]) {
	MazeSolver solverA("inputA.txt");
	MazeSolver solverB("inputB.txt");
	MazeSolver solverC("inputC.txt");
	MazeSolver solverD("inputD.txt");

	if (solverA.mazeIsReady()) {
		// solve mazes A
		solverA.solveMaze();
		solverA.printSolution();

		// solve mazes B
		solverB.solveMaze();
		solverB.printSolution();

		// solve mazes C
		solverC.solveMaze();
		solverC.printSolution();

		// solve mazes D
		solverD.solveMaze();
		solverD.printSolution();
	}

	return 0;
}
