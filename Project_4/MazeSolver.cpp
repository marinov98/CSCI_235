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
		std::cout << "Cannot read from " << input_file << "\n";
	}

	// get the rows and the columns of the maze

	Mazefile >> maze_rows_ >> maze_columns_;

	// initialize solution and maze
	if (maze_rows_ > 0 && maze_columns_ > 0) {
		// initialize the maze and the solution
		initializeMaze(maze_rows_, maze_columns_);
		// fill the maze BEFORE COPYING to solution
		fillMaze(Mazefile);

		initializeSolution();
	}

	Mazefile.close();
}

// destructor
MazeSolver::~MazeSolver() {
	// check to see if file was opened
	if (maze_ready) {
		// delete maze
		for (int i = 0; i < maze_rows_; ++i)
			delete[] maze_[i];

		delete[] maze_;
		maze_ = nullptr;

		// delete solution
		for (int j = 0; j < maze_rows_; ++j)
			delete[] solution_[j];

		delete[] solution_;
		solution_ = nullptr;
	}
}

// public functions
bool MazeSolver::mazeIsReady() {
	return maze_ready;
}

// attempts to solve the maze after it has been initialized
bool MazeSolver::solveMaze() {
	// keep track of your current position
	Position current = backtrack_stack_.top();

	while (!backtrack_stack_.empty()) {
		// CHECK: if the solution is one character away
		if (solution_[current.row][current.column] == '$') {
			std::cout << "Found the exit!!!" << "\n";
			return true;
		} // CHECK: if road can be extended
		else if (extendPath(current)) {
			solution_[current.row][current.column] = '>';
			current = backtrack_stack_.top();
		}
		else { // Backktracking
			maze_[current.row][current.column] = 'X';
			solution_[current.row][current.column] = '@';
			backtrack_stack_.pop();
			if (!backtrack_stack_.empty()) {
				current = backtrack_stack_.top();
			}
			else {
				std::cout << "This maze has no solution."
				          << "\n";
				return false;
			}
		}
	}
	// avoid warnings
	return false;
}

// prints the solution to the maze
void MazeSolver::printSolution() {
	std::cout << "The solution to this maze is:"
	          << "\n";
	for (int row = 0; row < maze_rows_; ++row) {
		for (int column = 0; column < maze_columns_; ++column) {
			std::cout << solution_[row][column] << ' ';
		}
		std::cout << '\n';
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
	for (int row = 0; row < maze_rows_; row++) {
		for (int column = 0; column < maze_columns_; column++) {
			// ignore spaces
			input_stream.ignore();
			input_stream.get(maze_[row][column]);
		}
	}
}

void MazeSolver::initializeSolution() {
	if (maze_ready) {
		// copy the maze to the solution
		copyMazetoSolution();
		// inialize stack with all viable paths
		Position viable{0, 0};
		// push initial position to stack
		backtrack_stack_.push(viable);
		// mark Solution
		solution_[0][0] = '>';
		// push all viable paths to stack
		if (isExtensible(viable, SOUTH)) {
			Position new_pos = getNewPosition(viable, SOUTH);
			backtrack_stack_.push(new_pos);
		}
		if (isExtensible(viable, EAST)) {
			Position new_pos = getNewPosition(viable, EAST);
			backtrack_stack_.push(new_pos);
		}
	}
}

void MazeSolver::copyMazetoSolution() {
	solution_ = new char*[maze_rows_];

	for (int row = 0; row < maze_rows_; row++) {
		solution_[row] = new char[maze_columns_];
	}
	// made solution
	for (int row = 0; row < maze_rows_; row++) {
		for (int column = 0; column < maze_columns_; column++) {
			solution_[row][column] = maze_[row][column];
		}
	}
}

bool MazeSolver::extendPath(Position current_position) {
	bool result = false;
	// check if its extensible going SOUTH first
	if (isExtensible(current_position, SOUTH)) {
		backtrack_stack_.push(getNewPosition(current_position, SOUTH));
		result = true;
	}
	// check if its extensible going EAST
	if (isExtensible(current_position, EAST)) {
		backtrack_stack_.push(getNewPosition(current_position, EAST));
		result = true;
	}

	return result;
}

Position MazeSolver::getNewPosition(Position old_position, direction dir) {
	if (isExtensible(old_position, dir)) {
		if (dir == SOUTH)
			old_position.row += 1;
		else
			old_position.column += 1;
	}

	return old_position;
}

bool MazeSolver::isExtensible(Position current_position, direction dir) {
	// variable to store whether the operation is successful or not
	bool result = false;

	// check for going down
	if (dir == SOUTH) {
		if (current_position.row + 1 < maze_rows_
		    && (maze_[current_position.row + 1][current_position.column] == '_'
		        || maze_[current_position.row + 1][current_position.column] == '$'))
			result = true;
	} // check for going right
	else {
		if (current_position.column + 1 < maze_columns_
		    && (maze_[current_position.row][current_position.column + 1] == '_'
		        || maze_[current_position.row][current_position.column + 1] == '$'))
			result = true;
	}

	return result;
}
