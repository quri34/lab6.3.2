#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

template<typename T>
void Create(T* a, const int size, T Low, T High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

template<typename T>
void Print(T* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int IFirst(int* a, const int size, int& max, int i)
{
	if (a[i] % 2 == 0)
	{
		max = a[i];
		return i;
	}
	if (i < size - 1)
		return IFirst(a, size, max, i + 1);
	else
		return -1;
}

template<typename T>
T IFirst(T* a, const int size, int& max, int i)
{
	if (a[i] % 2 == 0)
	{
		max = a[i];
		return i;
	}
	if (i < size - 1)
		return IFirst(a, size, max, i + 1);
	else
		return -1;
}

int Max(int* a, const int size, int max, int i)
{
	if (a[i] > max && a[i] % 2 == 0)
		max = a[i];
	if (i < size - 1)
		return Max(a, size, max, i + 1);
	else
		return max;
}

template<typename T>
T Max(T* a, const int size, T max, int i)
{
	if (a[i] > max && a[i] % 2 == 0)
		max = a[i];
	if (i < size - 1)
		return Max(a, size, max, i + 1);
	else
		return max;
}


int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "n = "; cin >> n;
	int* a = new int[n];
	int Low;
	cout << "Low= "; cin >> Low;
	int High;
	cout << "High = "; cin >> High;
	Create<int>(a, n, Low, High, 0);
	Print<int>(a, n, 0);
	int max;
	int imax = IFirst(a, n, max, 0);
	if (imax == -1)
		cerr << "немає елементів, які задовольняють умові" << endl;
	else
		cout << "max = " << Max<int>(a, n, max, imax + 1) << endl;
	return 0;

}
