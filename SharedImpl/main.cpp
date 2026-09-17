#include <memory>
#include <iostream>
using namespace std;

template <typename T>
class SharedPtr
{
private:
    T *data;
    size_t *ref_count;

public:
    explicit SharedPtr(T* other = nullptr) : data(other), ref_count(new size_t(1))
    {
        cout<<"constructor called"<<endl;
    }

    SharedPtr(const SharedPtr& other)
    {
        cout<<"copy constructor called"<<endl;
        data = other.data;
        ref_count = other.ref_count;
        (*ref_count)++;
    }
    
    void release()
    {
        if(ref_count && --(*ref_count) == 0)
        {
            delete data;
            delete ref_count;
            data = nullptr;
            ref_count = nullptr;
        }
    }
    
    SharedPtr& operator = (const SharedPtr& other)
    {
        cout<<"copy assignment operator called"<<endl;
        if(this != &other)
        {
            release();
            data = other.data;
            ref_count = other.ref_count;
            (*ref_count)++;
        }
        return *this;
    }

    SharedPtr(SharedPtr && other) noexcept
    {
        cout<<"move constructor called"<<endl;
        data = other.data;
        ref_count = other.ref_count;
        other.data = nullptr;
        other.ref_count = nullptr;
    }

    SharedPtr& operator = (SharedPtr && other) noexcept
    {
        if(this != &other)
        {
            release();
            data = other.data;
            ref_count = other.ref_count;
            other.data = nullptr;
            other.ref_count = nullptr;
        }
        cout<<"move assignment operator called"<<endl;
        return *this;
    }

    ~SharedPtr()
    {
        release();
    }

    T& operator * ()
    {
        if (data == nullptr)
            throw std::runtime_error("Dereferencing null pointer");
        return *data;
    }

    const T& operator * () const
    {
        if(data == nullptr)
        {
            throw std::runtime_error("Dereferencing null pointer");
        }
        
        return *data;
    }

    T* operator->() const noexcept
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
            release();
            data = other;
            ref_count = new size_t(1);
        }   
    }

    T* release () noexcept
    {
        T* temp = data;
        data = nullptr;
        ref_count = nullptr;
        return temp;
    }

    explicit operator bool() const noexcept
    {
        return data != nullptr;
    }

    size_t use_count() const noexcept
    {
        return ref_count ? *ref_count : 0;
    }
};

template <typename T, typename ...Args>
SharedPtr<T> make_shared1(Args&& ...args)
{
     return SharedPtr<T>(new T(forward<Args>(args)...));
}

int main()
{
    //UniquePtr<int> uPtr {new int(10)};
    SharedPtr<int> uPtr2 = make_shared1<int>(12);
    if(uPtr2)
    {
        cout<<"uPtr2 is not null"<<endl;
        cout<<"Value: "<<*uPtr2<<endl;
        cout<<"Use count: "<<uPtr2.use_count()<<endl;
    }
    else
    {
        cout<<"uPtr2 is null"<<endl;
    }
    //uPtr2.reset();
    // cout<<*uPtr<<endl;
}