#include <iostream>
#include <list>
#include <ctime>

using namespace std;

void create(list<int>& list, int n)
{
	for (int i = 0; i < n; i++)
		list.push_back(rand() % 100 - 50);
}

void print(list<int> list, int n)
{
	for (int i = 0; i < n; i++)
	{
		int k = list.front();
		list.pop_front();
		cout << k << " ";
		list.push_back(k);
	}
	cout << endl;
}

double count(list<int> list, int n)
{
	int sumP = 0;
	for (int i = 0; i < n; i++)
	{
		int k = list.front();
		list.pop_front();
		if (k > 0)
		{
			sumP += k;
		}
		list.push_back(k);
	}
	return sumP;
}

int main()
{
	srand((unsigned int)time(NULL));
	int n;
	cout << "n = ? "; cin >> n;
	list<int> arr;
	create(arr, n);
	print(arr, n);
	cout << "sum positive = " << count(arr, n) << endl;
	return 0;
}
