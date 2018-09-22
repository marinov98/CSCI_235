#include <iostream>

int main()
{
	int numbers[7] = {1, 2, 55, 66, 33, 24, 45};

	for (int i : numbers)
	{
		std::cout << i << '\n';
	}
	// output : 1 - 45 with an end of line
	return 0;
}
