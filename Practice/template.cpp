#include <iostream>
#include <string>

template <typename T>

void Print(T value)
{
	std::cout << value << '\n';
}

// Array example
template <typename T, int N>
class Array
{
  private:
	T m_Array[N];

  public:
	int GetSize() const
	{
		return N;
	}
};

int main()
{
	// Print example
	Print(5);
	Print(24.25);
	Print(44.12345);
	Print("Template mothertrucker");

	// Array example
	// Array<int, 25> array;
	Array<std::string, 50> array;
	std::cout << array.GetSize() << '\n';

	return 0;
}
