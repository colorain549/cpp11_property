#include <iostream>
#include <memory>
#include <vector>

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

int main()
{
    // 不能直接获取资源
    // weak_ptr<Point> wp(new Point(1, 2));
    weak_ptr<Point> wp;
    {
        shared_ptr<Point> sp(new Point(1, 2));
        wp = sp;
        cout << wp.use_count() << endl; //  1
        cout << sp.use_count() << endl; //  1

        // 不能直接获取资源
        cout << wp.expired() << endl;   // 0
        // 判断共享资源是否已经销毁的方式是从wp提升为sp
        shared_ptr<Point> sp2 = wp.lock();

        if (sp2)
        {
            cout << "up successfully" << endl;
        }
        else
        {
            cout << "up fail" << endl;
        }
    }

    cout << wp.expired() << endl;

    shared_ptr<Point> sp2 = wp.lock();
    if (sp2)
    {
        cout << "up successfully" << endl;
    }
    else
    {
        cout << "up fail" << endl;
    }

    return 0;
}