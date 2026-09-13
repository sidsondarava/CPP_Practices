#include "vector.h"

template <typename T>
Vector<T>::Vector(size_t requestedSize)
{
    data = new T[requestedSize];
    size = requestedSize;
    capacity = requestedSize;
    cout<<"Vector(size_t requestedSize)"<<endl;
}

template <typename T>
Vector<T>::Vector(size_t requestedSize, T defaultValue)
{
    data = new T[requestedSize];
    size = requestedSize;
    capacity = requestedSize;
    for(size_t i = 0; i < requestedSize; i++)
    {
        data[i] = defaultValue;
    }
    cout<<"Vector(size_t requestedSize, T defaultValue)"<<endl;
}

template <typename T>
Vector<T>::Vector(const Vector& vec)
{
    data = new T[vec.capacity];
    for(size_t i = 0; i < vec.size; i++)
    {
        data[i] = vec.data[i];
    }
    capacity = vec.capacity;
    size = vec.size;
    cout<<"Vector(const Vector& vec)"<<endl;
}

template <typename T>
Vector<T>& Vector<T>::operator =(const Vector& vec)
{
    if(this != &vec)
    {
        T* newData = new T[vec.capacity];
        for(size_t i = 0; i < vec.size; i++)
        {
            newData[i] = vec.data[i];
        }
        delete []data;
        data = newData;
        capacity = vec.capacity;
        size = vec.size;

        cout<<"operator = (const Vector& vec)"<<endl;
    }
    return *this;
}

template <typename T>
Vector<T>::Vector(Vector &&vec) noexcept
{
    data = vec.data;
    size = vec.size;
    capacity = vec.capacity;
    vec.data = nullptr;
    cout<<"Vector(Vector &&vec)"<<endl;
}

template <typename T>
Vector<T>& Vector<T>::operator =(Vector&& vec)
{
    if(this != &vec)
    {
        delete []data;
        data = vec.data;
        size = vec.size;
        capacity = vec.capacity;
        vec.data = nullptr;

        cout<<"operator =(Vector&& vec)"<<endl;
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete []data;
    data = nullptr;
}

template <typename T>
size_t Vector<T>::GetSize() const
{
    return size;
}

template <typename T>
void Vector<T>::push_back(T value)
{
    if (size < capacity)
    {
        data[size++] = value;
        return;
    }

    size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;

    T* temp = new T[newCapacity];

    for (size_t i = 0; i < size; ++i)
    {
        temp[i] = data[i];
    }

    temp[size] = value;

    delete[] data;

    data = temp;
    ++size;
    capacity = newCapacity;
        
}

template <typename T>
void Vector<T>::pop_back()
{
    if(size > 0)
        size--;
}

template <typename T>
T& Vector<T>::operator [](size_t idx)
{
    return data[idx];
}


template class Vector<int>;