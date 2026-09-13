#pragma once
#include<iostream>
using namespace std;

template <typename T>
class Vector;

template <typename T>
ostream& operator <<(ostream &, const Vector<T>&);

template <typename T>
istream& operator >>(istream &, Vector<T>&);

template <typename T>
class Vector {
    T *data = nullptr;
    size_t capacity = 0;
    size_t size = 0;

public:
    //constructors
    Vector() = default;
    Vector(size_t requestedSize);
    Vector(size_t requestedSize, T defaultValue);
    Vector(const Vector& vec);
    Vector(Vector && vec) noexcept;
    ~Vector();

    //utilities
    Vector& operator =(const Vector& vec);
    Vector& operator =(Vector&& vec);
    T& operator [](size_t idx);
    size_t GetSize() const;
    void push_back(T value);
    void pop_back();

    //friend entiry
    friend ostream& operator << <T>(ostream &, const Vector<T>&);
    friend istream& operator >> <T>(istream &, Vector<T>&);
};


template <typename T>
ostream& operator <<(ostream &os, const Vector<T>& vec)
{
    for(size_t i = 0; i < vec.size; i++)
    {
        os << vec.data[i]<<" ";
    }
    return os;
}

template <typename T>
istream& operator >>(istream &is, Vector<T>& vec)
{
    for(size_t i = 0; i < vec.size; i++)
    {
        is >> vec.data[i];
    }
    return is;
}