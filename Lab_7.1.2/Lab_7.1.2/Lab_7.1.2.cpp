#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int RandomNumber() { return rand() % 1999 - 999; } // від -999 до 999

void print(const vector<int>& a)
{
	for (int i : a)
		cout << i << " ";
	cout << endl;
}

double findMaxIndex(const vector<int>& v)
{
	double maxIndex = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] > v[(int)maxIndex])
			maxIndex = i;
	}
	cout << "Max element: " << v[(int)maxIndex] << " at index " << maxIndex << endl;
	return maxIndex;
}

double findMinIndex(const vector<int>& v)
{
	double minIndex = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] < v[(int)minIndex])
			minIndex = i;
	}
	cout << "Min element: " << v[(int)minIndex] << " at index " << minIndex << endl;
	return minIndex;
}

double avgIndices(double index1, double index2)
{
	return (index1 + index2) / 2.0;
}

int main()
{
	srand(unsigned(time(0)));
	int n;
	cout << "n = ? "; cin >> n;

	vector<int> v(n);
	generate(v.begin(), v.end(), RandomNumber);
	print(v);

	double maxIndex = findMaxIndex(v);
	double minIndex = findMinIndex(v);
	double avg = avgIndices(minIndex, maxIndex);

	cout << "Average of indices: " << avg << endl;

	return 0;
}
