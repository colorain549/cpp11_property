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

void test0()
{
    unique_ptr<Point>(new Point(2, 3));
}

int main()
{
    unique_ptr<int> up(new int(10));
    cout << *up << endl;
    cout << up.get() << endl;

    // 不能复制(2)

    unique_ptr<int> up2(std::move(up));
    cout << *up2 << endl;
    cout << up2.get() << endl;

    unique_ptr<Point> upt(new Point(1, 2));
    vector<unique_ptr<Point>> numbers;
    numbers.push_back(unique_ptr<Point>(new Point(2, 3)));
    numbers.push_back(std::move(upt));
    for (auto &elem : numbers)
    {
        elem->print();
    }

    unique_ptr<Point>(new Point(2, 3));

    return 0;
}