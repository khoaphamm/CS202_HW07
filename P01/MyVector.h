#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

template <class T>
class MyVector
{
private:
    T *arr;
    int size;
    int capacity;

    void resize(int newCapacity);

public:
    MyVector();                  // Default constructor
    MyVector(int n);             // Constructor with n zeros
    MyVector(T *a, int n);       // Constructor with array
    MyVector(const MyVector &v); // Copy constructor
    ~MyVector();                 // Destructor

    int getSize();
    T getItem(int index);
    void setItem(T value, int index);
    void add(T value);
    void addRange(T *a, int n);
    void clear();
    bool contains(T value);
    void toArray(T *outputArr, int &n);
    bool equals(const MyVector &v);
    int indexOf(T value);
    int lastIndexOf(T value);
    void insert(T value, int index);
    void remove(T value);
    void removeAt(int index);
    void reverse();
    string toString();
    void sortAsc();
    void sortDesc();
};

#include "MyVector.cpp"

#endif