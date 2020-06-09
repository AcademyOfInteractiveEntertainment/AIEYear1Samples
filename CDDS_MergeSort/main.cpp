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

void merge(int* const array, int startIdx, int midIdx, int endIdx)
{
	int leftEnd = midIdx - startIdx + 1;
	int rightEnd = endIdx - midIdx;

	int* leftArray = new int[leftEnd];
	int* rightArray = new int[rightEnd];

	for (int i = 0; i < leftEnd; i++) {
		leftArray[i] = array[startIdx + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		rightArray[j] = array[midIdx + j + 1];
	}

	int i = 0;
	int j = 0;
	for (int k = startIdx; k <= endIdx; k++) {
		if (j >= rightEnd || i < leftEnd && leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			i++;
		}
		else {
			array[k] = rightArray[j];
			j++;
		}
	}

	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(int* const array, int startIdx, int endIdx)
{
	if (startIdx < endIdx)
	{
		int midIdx = (startIdx + endIdx) / 2;
		mergeSort(array, startIdx, midIdx);
		mergeSort(array, midIdx+1, endIdx);
		merge(array, startIdx, midIdx, endIdx);
	}
}

int main()
{
	const int size = 100;

	// create a large array
	int* values = new int[size];
	int* valuesToSort = new int[size];

	srand((unsigned int)time(nullptr));
	// and fill it with some ordered data
	for (int i = 0; i < size; i++) {
		values[i] = rand() % size;
	}

	high_resolution_clock::time_point t1, t2;

	// Profile Bubble Sort
	memcpy(valuesToSort, values, sizeof(int)*size);

	t1 = high_resolution_clock::now();
	bubbleSort(valuesToSort, size);
	t2 = high_resolution_clock::now();

	for (int i = 0; i < size; i++) {
		std::cout << valuesToSort[i] << ", ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Bubble Sort took " << (t2 - t1).count() << " nanoseconds" << std::endl;

	// pause
	std::cout << "press any key to profile Merge Sort" << std::endl;
	std::cin.get();
	std::cout << std::endl;


	// Profile Merge Sort
	memcpy(valuesToSort, values, sizeof(int)*size);

	t1 = high_resolution_clock::now();
	mergeSort(valuesToSort, 0, size-1);
	t2 = high_resolution_clock::now();

	for (int i = 0; i < size; i++) {
		std::cout << valuesToSort[i] << ", ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Merge Sort took " << (t2 - t1).count() << " nanoseconds" << std::endl;


	delete[] values;
	delete[] valuesToSort;

	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
	return 0;
}