#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(int* const array, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}

int main()
{
	const int size = 100;

	// create a large array
	int* values = new int[size];

	srand(time(nullptr));
	// and fill it with some ordered data
	for (int i = 0; i < size; i++) {
		values[i] = rand() % size;
	}

	high_resolution_clock::time_point t1, t2;

	t1 = high_resolution_clock::now();
	bubbleSort(values, size);
	t2 = high_resolution_clock::now();


	for (int i = 0; i < size; i++) {
		std::cout << values[i] << ", ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "bubble sort took " << (t2 - t1).count() << " nanoseconds" << std::endl;

	delete[] values;

	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
	return 0;
}