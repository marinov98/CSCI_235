#include <iostream>
#include "MazeSolver.h"

int main(int argc, char *argv[])
{
  MazeSolver solver("input.txt");
  
  if(solver.mazeIsReady()) {    
    solver.solveMaze();

    solver.printSolution();
 }
  return 0;
}

