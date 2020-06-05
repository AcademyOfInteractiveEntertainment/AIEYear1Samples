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

int partition(int* const array, int p, int r)
{
	int temp;
	int x = array[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (array[j] <= x) {
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[r];
	array[r] = temp;

	return i + 1;
}

void quickSort(int* const array, int p, int r)
{
	if (p < r)
	{
		int q = partition(array, p, r);
		quickSort(array, p, q - 1);
		quickSort(array, q + 1, r);
	}
}

int main()
{
	const int size = 100;

	// create a large array
	int* values = new int[size];
	int* valuesToSort = new int[size];

	srand(time(nullptr));
	// and fill it with some ordered data
	for (int i = 0; i < size; i++) {
		values[i] = rand() % size;
	}

	high_resolution_clock::time_point t1, t2;

	// Profile Bubble Sort
	memcpy(valuesToSort, values, sizeof(int) * size);

	t1 = high_resolution_clock::now();
	bubbleSort(valuesToSort, size);
	t2 = high_resolution_clock::now();

	for (int i = 0; i < size; i++) {
		std::cout << valuesToSort[i] << ", ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Bubble Sort took " << (t2 - t1).count() << " nanoseconds" << std::endl;

	// pause
	std::cout << "press any key to profile Insertion Sort" << std::endl;
	std::cin.get();
	std::cout << std::endl;


	// Profile Quick Sort
	memcpy(valuesToSort, values, sizeof(int) * size);

	t1 = high_resolution_clock::now();
	quickSort(valuesToSort, 0, size - 1);
	t2 = high_resolution_clock::now();

	for (int i = 0; i < size; i++) {
		std::cout << valuesToSort[i] << ", ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Quick Sort took " << (t2 - t1).count() << " nanoseconds" << std::endl;


	delete[] values;
	delete[] valuesToSort;

	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
	return 0;
}