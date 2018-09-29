/*
A left rotation operation on an array of size
shifts each of the array's elements  unit to the left.
For example, if left rotations are performed on array ,
then the array would become .

Given an array of  integers and a number, ,
perform  left rotations on the array.
Then print the updated array as a single line of space-separated integers.

Input Format
The first line contains two space-separated integers
denoting the respective values of
(the number of integers) and
(the number of left rotations you must perform).
The second line contains
 space-separated integers describing the respective elements of the array's initial state.
*/

#include <iostream>
#include <vector>

void leftShift(std::vector<int> dataset, int d) {
	int temp;
	int temp2;

	while (d > 0) {
		// right shift
		// temp = dataset.front();
		// dataset.pop_back();
		// dataset.push_back(temp);

		// left shift
		temp = dataset[0];
		for (int i = 1; i < dataset.size(); i++) {
			dataset[i - 1] = dataset[i];
		}
		dataset[dataset.size() - 1] = temp;
		d--;
	}

	for (int i = 0; i < dataset.size(); i++) {
		std::cout << " " << dataset[i];
	}
}

// 1 2 3 4 5
// 5 1 2 3 4 d = 1

// 1 2 3 4 5
// 3 4 5 1 2  d = 3
int main() {
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);

	leftShift(nums, 3);
}