// Lab_06_4.cpp
// < Величко Іван >
// Лабораторна робота № 6.4
// Шаблони класів та шаблони функцій 
// Варіант 0.4

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

template <class T> // T - тип
class vector
{
	T* v;				// внутрішній масив
	int size;			// кількість елементів
public:
	vector(int newsize);				 // конструктор ініціалізації
	vector(vector&);					 // конструктор копіювання
	~vector();							 // деструктор
	T extr(const char*);				 // пошук мінімального чи максимального елемента
	vector& sort(const char*);			 // сортування

	T& operator [] (int index);			 // індексування
	vector& operator = (const vector&);  // присвоєння
	friend ostream& operator << <>(ostream&, vector&); // виведення
	friend istream& operator >> <>(istream&, vector&); // введення
};

template <class T>
vector<T>::vector(int newsize)			// конструктор ініціалізації
{
	v = new T[size = newsize];			// новий розмір, виділення пам'яті для елементів
	for (int i = 0; i < size; i++)		// присвоєння нульових значень елементам
		v[i] = T();
}

template <class T>
vector<T>::vector(vector<T>& x)			// конструктор копіювання
{
	v = new T[size = x.size];			// новий розмір, виділення пам'яті для елементів
	for (int i = 0; i < size; i++)		// присвоєння значень елементам
		v[i] = x.v[i];
}

template <class T>
vector<T>::~vector()
{
	delete[] v;		// звільнення пам'яті
}

template <class T>
T vector<T>::extr(const char* MinOrMax)				// MinOrMax - визначає, що шукаємо
{
	T ExtrElem = v[0];
	for (int i = 0; i < size; i++) {
		if (!strcmp(MinOrMax, "min")) {
			if (v[i] < ExtrElem) ExtrElem = v[i];	// мінімальний елемент 
		}
		else
			if (v[i] > ExtrElem) ExtrElem = v[i];	// максимальний елемент
	}
	return ExtrElem;
}

template <class T>
vector<T>& vector<T>::sort(const char* UpOrDown)
{ // UpOrDown - порядок сортування
	T x;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (!strcmp(UpOrDown, "up"))
			{							// за зростанням
				if (v[i] > v[j])
				{
					x = v[i];
					v[i] = v[j];
					v[j] = x;
				}
			}
			else						// за спаданням
				if (v[i] < v[j])
				{
					x = v[i];
					v[i] = v[j];
					v[j] = x;
				}
	return *this;
}

template <class T>
T& vector<T>::operator [] (int index)  // Інксуємо за індексом
{
	// Перевірка на коректність індексу
	if (index < 0 || index >= size) {
		throw out_of_range("Index out of range");
	}
	return v[index];  // Повертаємо елемент за індексом
}

template <class T>
vector<T>& vector<T>::operator = (const vector<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}

template <class T>
istream& operator >> (istream& is, vector<T>& x)
{
	cout << "Input " << x.size << " elements of vector" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] = ? ";
		is >> x.v[i];
	}
	return is;
}

template <class T>
ostream& operator << (ostream& os, vector<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}

int main()
{
	try
	{
		vector<int> V(10);
		cin >> V;
		cout << "min element = " << V.extr("min") << endl;

		V.sort("down");
		cout << "sorted down:" << endl;
		cout << V;

		V.sort("up");
		cout << "sorted up:" << endl;
		cout << V;
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	system("pause");
	return 0;
}