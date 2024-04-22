#include <iostream>

using namespace std;

class Point
{
public:
    Point(int ix, int iy) : _ix(ix), _iy(iy) {}
    void print()
    {
        cout << _ix << ", " << _iy << endl;
    }

private:
    int _ix;
    int _iy;
};

// 模版类
template <class T>
class RAII
{
public:
    // 通过构造函数托管资源
    RAII(T *data) : _data(data)
    {
        cout << "RAII(T *data)" << endl;
    }

    // 访问资源的方法
    // _data为指针(地址)
    T *operator->()
    {
        return _data;
    }

    // 使用 operator* 访问资源
    T &operator*()
    {
        return *_data;
    }

    // 使用 get 获取指针
    T *get() const
    {
        return _data;
    }

    // 通过reset更换资源
    void reset(T *data)
    {
        if (_data)
        {
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }

    RAII(const RAII &rhs) = delete;
    RAII &operator=(const RAII &rhs) = delete;

    // 通过析构函数释放资源
    ~RAII()
    {
        cout << "~RAII()" << endl;
        if (_data)
        {
            delete _data;
            _data = nullptr;
        }
    }

private:
    T *_data;
};

int main()
{
    RAII<Point> ppt(new Point(1, 2));
    ppt->print();

    cout << ppt.operator->() << endl;

    // 访问资源的方法
    RAII<int> mypi(new int(42));
    cout << *(mypi.operator->()) << endl;

    // 使用 operator* 访问资源
    cout << *mypi << endl;

    // 使用 get 获取指针
    int *getPointer = mypi.get();
    cout << *getPointer << endl; // 输出: 42

    // 通过reset更换资源
    mypi.reset(new int(99));
    cout << *mypi << endl; // 输出: 99

    return 0;
}