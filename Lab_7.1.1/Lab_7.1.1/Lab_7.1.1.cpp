#include <iostream>
#include <array>
#include <ctime>

using namespace std;

void create(array<int, 100>& arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 1999 - 999; // значення від -999 до 999
}

void print(const array<int, 100>& arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

double findMaxIndex(const array<int, 100>& arr, int n)
{
	double maxIndex = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[(int)maxIndex])
			maxIndex = i;
	}
	cout << "Max element: " << arr[(int)maxIndex] << " at index " << maxIndex << endl;
	return maxIndex;
}

double findMinIndex(const array<int, 100>& arr, int n)
{
	double minIndex = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[(int)minIndex])
			minIndex = i;
	}
	cout << "Min element: " << arr[(int)minIndex] << " at index " << minIndex << endl;
	return minIndex;
}

double avgIndices(double index1, double index2)
{
	return (index1 + index2) / 2.0;
}

int main()
{
	srand((unsigned int)time(NULL));
	int n;
	cout << "n = ? ( <= 100)"; cin >> n;
	array<int, 100> arr = { 0 };

	create(arr, n);
	print(arr, n);

	double maxIndex = findMaxIndex(arr, n);
	double minIndex = findMinIndex(arr, n);

	double avg = avgIndices(minIndex, maxIndex);
	cout << "Average of indices: " << avg << endl;

	return 0;
}
