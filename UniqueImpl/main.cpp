#include <memory>
#include <iostream>
using namespace std;

template <typename T>
class UniquePtr
{
private:
    T *data;

public:
    explicit UniquePtr(T* other = nullptr) : data(other)
    {
        cout<<"constructor called"<<endl;
    }

    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr& operator = (const UniquePtr& other) = delete;

    UniquePtr(UniquePtr && other) noexcept
    {
        cout<<"move constructor called"<<endl;
        data = other.data;
        other.data = nullptr;
    }

    UniquePtr& operator = (UniquePtr && other) noexcept
    {
        if(this != &other)
        {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        cout<<"move assignment operator called"<<endl;
        return *this;
    }

    ~UniquePtr()
    {
        delete data;
    }

    T& operator * ()
    {
        return *data;
    }

    const T& operator * () const
    {
        return *data;
    }

    T* operator ->() const noexcept
    {
        return data;
    }

    T* get() const noexcept
    {
        return data;
    }

    void reset(T *other = nullptr) noexcept
    {
        if(data != other)
        {
            delete data;
            data = other;
        }   
    }

    T* release () noexcept
    {
        T* temp = data;
        data = nullptr;
        return temp;
    }

    explicit operator bool() const noexcept
    {
        return data != nullptr;
    }
};

template <typename T, typename ...Args>
UniquePtr<T> make_unique1(Args&& ...args)
{
     return UniquePtr<T>(new T(forward<Args>(args)...));
}

int main()
{
    //UniquePtr<int> uPtr {new int(10)};
    UniquePtr<int> uPtr2 = make_unique1<int>(12);
    //uPtr2.reset();
    // cout<<*uPtr<<endl;
}