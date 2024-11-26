#ifndef MYVECTOR_CPP
#define MYVECTOR_CPP

#include "MyVector.h"

// Resize the internal array
template <class T>
void MyVector<T>::resize(int newCapacity)
{
    T *newArr = new T[newCapacity];
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

// Default constructor
template <class T>
MyVector<T>::MyVector() : arr(nullptr), size(0), capacity(0) {}

// Constructor with n zeros
template <class T>
MyVector<T>::MyVector(int n) : size(n), capacity(n)
{
    arr = new T[n]();
}

// Constructor with array
template <class T>
MyVector<T>::MyVector(T *a, int n) : size(n), capacity(n)
{
    arr = new T[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }
}

// Copy constructor
template <class T>
MyVector<T>::MyVector(const MyVector &v) : size(v.size), capacity(v.capacity)
{
    arr = new T[v.capacity];
    for (int i = 0; i < v.size; i++)
    {
        arr[i] = v.arr[i];
    }
}

// Destructor
template <class T>
MyVector<T>::~MyVector()
{
    delete[] arr;
}

// Get size of vector
template <class T>
int MyVector<T>::getSize()
{
    return size;
}

// Get item at index
template <class T>
T MyVector<T>::getItem(int index)
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    return arr[index];
}

// Set item at index
template <class T>
void MyVector<T>::setItem(T value, int index)
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    arr[index] = value;
}

// Add value to the end
template <class T>
void MyVector<T>::add(T value)
{
    if (size == capacity)
    {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    arr[size++] = value;
}

// Add range of values
template <class T>
void MyVector<T>::addRange(T *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        add(a[i]);
    }
}

// Clear the vector
template <class T>
void MyVector<T>::clear()
{
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

// Check if vector contains value
template <class T>
bool MyVector<T>::contains(T value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return true;
    }
    return false;
}

// Convert to array
template <class T>
void MyVector<T>::toArray(T *outputArr, int &n)
{
    n = size;
    for (int i = 0; i < size; i++)
    {
        outputArr[i] = arr[i];
    }
}

// Check if two vectors are equal
template <class T>
bool MyVector<T>::equals(const MyVector &v)
{
    if (size != v.size)
        return false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != v.arr[i])
            return false;
    }
    return true;
}

// Get index of value
template <class T>
int MyVector<T>::indexOf(T value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Get last index of value
template <class T>
int MyVector<T>::lastIndexOf(T value)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Insert value at index
template <class T>
void MyVector<T>::insert(T value, int index)
{
    if (index < 0 || index > size)
        throw out_of_range("Index out of range");
    if (size == capacity)
        resize(capacity == 0 ? 1 : capacity * 2);
    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
}

// Remove value from vector
template <class T>
void MyVector<T>::remove(T value)
{
    int index = indexOf(value);
    if (index != -1)
        removeAt(index);
}

// Remove item at index
template <class T>
void MyVector<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Reverse the vector
template <class T>
void MyVector<T>::reverse()
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }
}

// Convert vector to string
template <class T>
string MyVector<T>::toString()
{
    stringstream ss;
    ss << "[";
    for (int i = 0; i < size; i++)
    {
        ss << arr[i];
        if (i < size - 1)
            ss << ", ";
    }
    ss << "]";
    return ss.str();
}

// Sort in ascending order
template <class T>
void MyVector<T>::sortAsc()
{
    sort(arr, arr + size);
}

// Sort in descending order
template <class T>
void MyVector<T>::sortDesc()
{
    sort(arr, arr + size, greater<T>());
}

#endif
