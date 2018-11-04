// Assignment: CSCI 235, Fall 2018, Project 4
// Name: Marin Pavlinov Marinov
// Date: 11/01/18
// File Name: MazeSolver.cpp
// This file implements the MazeSolver class

#include "MazeSolver.h"
// constructor
MazeSolver::MazeSolver(std::string input_file) {
	std::ifstream Mazefile;

	// test to see if file can be opened
	try {
		Mazefile.open(input_file);
	}
	catch (int e) {
		std::cout << "Cannot read from input_file_name\n";
	}

	// get the rows and the columns of the maze
	Mazefile >> maze_rows_ >> maze_columns_;

	if (maze_rows_ > 0 && maze_columns_ > 0) {
	    
	        // initialize the maze and the solution 
		initializeMaze(maze_rows_, maze_columns_);
		initializeSolution();

		// fill the maze 
		fillMaze(Mazefile);
	}
}

MazeSolver::~MazeSolver() {
	// delete maze
	delete[] maze_;
	maze_ = nullptr;
	// delete solution
	delete[] solution_;
	solution_ = nullptr;
}

// public functions
bool MazeSolver::mazeIsReady() {
	return maze_ready;
}

bool MazeSolver::solveMaze() {}

void MazeSolver::printSolution() {
	for (int row = 0; row < maze_rows_; ++row) {
		for (int column = 0; column < maze_columns_; ++column) {
			std::cout << solution_[row][column] << "\n";
		}
	}
}

// private helper functions
void MazeSolver::initializeMaze(int rows, int columns) {
	maze_ = new char*[rows];

	for (int row = 0; row < rows; ++row)
		maze_[row] = new char[columns];

	maze_ready = true;
}

void MazeSolver::fillMaze(std::ifstream& input_stream) {
	for (int row = 0;  row < maze_rows_;  row++) {
		for (int column = 0; column < maze_columns_; column++) {
		    // ignore the spaces and add only the symbols
			input_stream.ignore();
			input_stream.get(maze_[ row][column]);
		}
	}
}

void MazeSolver::initializeSolution() {
    if (maze_ready) {
	// intialize solution
	solution_ = new char*[maze_rows_];

	for (int row = 0; row < maze_rows_; ++row) {
	    solution_[row] = new char[maze_columns_];
	}
	// copy the maze to the solution
	copyMazetoSolution();
    }
}

void MazeSolver::copyMazetoSolution() {
    for (int row = 0; row < maze_rows_; ++row) {
	for (int column = 0; column < maze_columns_; ++column) {
	    solution_[row][column] = maze_[row][column];
	}

    }
}

bool MazeSolver::extendPath(Position current_position) {}

Position MazeSolver::getNewPosition(Position old_position, direction dir) {}

bool MazeSolver::isExtensible(Position current_position, direction dir) {}
