/*
    Ivan Ao

    11/9/2020

    CS A250

    PE3
*/
#ifndef TARRAY_H
#define TARRAY_H

#include <iostream>

template<typename T>
class TArray
{

    template<typename T>
    friend std::ostream& operator<<(std::ostream& out, const TArray<T>& arr);       //friend function
	
public:
   
    TArray() : capacity{ 10 }, numElem{ 0 }, a{ new T[capacity] } {}                //default constructor
    
    TArray(int length) : capacity{ length }, numElem{ 0 }, a{ new T[capacity] }{}   //constructor
    
    TArray(const TArray& otherArray);                                               //copy constructor
    
    TArray<T>& operator=(const TArray& rightSide);                                     //copy assignment operator
    
    int& operator[](int) const;                                                     //overload subscript operator
    
    //member function
    void insert(T);

    void printArray() const;

    //destructor
    ~TArray();

private:
    int capacity, numElem;
    T* a;

};

#endif 