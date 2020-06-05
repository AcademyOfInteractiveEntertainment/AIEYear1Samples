#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int linearSearch(const int* const array, int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (value == array[i])
			return i;
	}
	return -1;
}

int binarySearch(const int* const array, int size, int value)
{
	int max = size - 1;
	int min = 0;
	int middle = 0;

	while (max != min)
	{
		middle = (min + max) / 2;
		if (array[middle] == value)
			return middle;
		else if (array[middle] > value)
			max = middle - 1;
		else
			min = middle + 1;
	}
	return -1;
}


int main()
{
	const int size = 100000;

	int searchKey;
	int idx;

	// array to store our search times
	long long searchTimes[10][2];
	long long totalLinear = 0;
	long long totalBinary = 0;

	high_resolution_clock::time_point t1, t2;


	// create a large array
	int* values = new int[size];

	// and fill it with some ordered data
	for (int i = 0; i < size; i++) {
		values[i] = i;
	}

	srand(time(nullptr));


	std::cout << "profiling ";

	for (int i = 0; i < 10; i++)
	{
		std::cout << ".";

		// perform a series of searchers and record the times

		// randomly choose a value to search for
		searchKey = (rand() * rand()) % size;

		// do a linear search
		t1 = high_resolution_clock::now();
		idx = linearSearch(values, size, searchKey);
		t2 = high_resolution_clock::now();

		searchTimes[i][0] = duration_cast<nanoseconds>(t2 - t1).count();

		// now do a binary search
		t1 = high_resolution_clock::now();
		idx = binarySearch(values, size, searchKey);
		t2 = high_resolution_clock::now();

		searchTimes[i][1] = duration_cast<nanoseconds>(t2 - t1).count();


		// keep a running total of the search times for both searches and display the result
		totalLinear += searchTimes[i][0];
		totalBinary += searchTimes[i][1];
	}
	std::cout << std::endl;

	// average the search times for both searches and display the result
	std::cout << "average linear search time was " << totalLinear / 10 << " nanoseconds" << std::endl;
	std::cout << "average binary search time was " << totalBinary / 10 << " nanoseconds" << std::endl;

	delete[] values;

	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	return 0;
}