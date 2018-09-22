#include <iostream>
#include <string>

template <typename T>

void Print(T value)
{
	std::cout << value << '\n';
}

int main()
{
	Print(5);
	Print(24.25);
	Print(44.12345);
	Print("Template mothertrucker");
	/* code */
	return 0;
}
