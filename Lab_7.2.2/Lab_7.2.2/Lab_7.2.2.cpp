#include <iostream> // std::cout
#include <list> // std::list
#include <algorithm> // std::generate
#include <ctime> // std::time
#include <numeric> // std::accumulate

using namespace std;

// function generator:
int RandomNumber() { return rand() % 100 - 50; }

void print(list<int> a)
{
	for (int i : a)
		cout << i << " ";
	cout << endl;
}

// Функція для обчислення суми додатних елементів
int sumOfPositiveElements(const list<int>& l) {
    return accumulate(l.begin(), l.end(), 0, [](int acc, int val) {
        return val > 0 ? acc + val : acc;
        });
}

int main()
{
    srand((unsigned int)time(NULL));
    int n;
    cout << "n = ? "; cin >> n;

    list<int> l(n);
    generate(l.begin(), l.end(), RandomNumber); // Генерація випадкових чисел
    print(l);

    int sum = sumOfPositiveElements(l); // Виклик функції та збереження результату

    cout << "sum positive = " << sum << endl; // Виведення суми додатних елементів
    return 0;
}