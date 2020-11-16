/*
	Ivan Ao

	11/9/2020

	CS A250

	PE3
*/
#include "TArray.h"

using namespace std;


template<typename T>
TArray<T>::TArray(const TArray& other)
	: capacity{ other.capacity }, numElem{ other.numElem }, a{ new T[capacity] }
{
	for (int i = 0; i < numElem; ++i)
	{
		a[i] = other.a[i];			
	}
}

template<typename T>
TArray<T>& TArray<T>::operator=(const TArray& right)
{
	if (&right != this)
	{
		if (capacity != right.capacity)
		{
			delete[] a;
			capacity = right.capacity;
			a = new T[capacity];
		}
		numElem = right.numElem;
		for (int i = 0; i < numElem; ++i)
		{
			a[i] = right.a[i];
		}
	}
	
	return *this;
}

template<typename T>
int& TArray<T>::operator[](int index) const
{
	if (index >= numElem)
	{
		cerr << "Not a valid index\n";
		exit(1);
	}
	else
	{
		return *(a + index);
	}
}

template<typename T>
void TArray<T>::insert(T num)
{
	bool find = false;
	for (int i = 0; i < numElem; ++i)
	{
		if (a[i] == num && find == false)
		{
			find = true;
		}
	}

	if (find)
	{
		cerr << num <<" was a duplicate\n";
	}
	else
	{
		a[numElem] = num;
		++numElem;
	}
}

template<typename T>
void TArray<T>::printArray() const
{
	cout << "[" << a[0];
	for (int i = 1; i < numElem; ++i)
	{
		cout << "," << a[i];
	}
	cout << "]" << endl;
}

template<typename T>
ostream& operator<<(ostream& out, const TArray<T>& arr)
{
	out << "[" << arr.a[0];
	for (int i = 1; i < arr.numElem; ++i)
	{
		out << "," << arr.a[i];
	}
	out << "]" << endl;
	return out;
}

template<typename T>
TArray<T>::~TArray()
{
	delete[] a;
}