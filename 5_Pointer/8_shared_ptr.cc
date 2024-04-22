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
    shared_ptr<int> sp(new int(10));
    cout << *sp << endl;            // 10
    cout << sp.get() << endl;       // 0x...aeb0
    cout << sp.use_count() << endl; // 1

    {
        shared_ptr<int> sp2(sp);
        cout << *sp << endl;             // 10
        cout << sp.get() << endl;        // 0x...aeb0
        cout << sp.use_count() << endl;  // 2
        cout << *sp2 << endl;            // 10
        cout << sp2.get() << endl;       // 0x...aeb0
        cout << sp2.use_count() << endl; // 2
    }

    cout << endl;

    shared_ptr<int> sp3(new int(20));
    sp3 = sp;
    cout << *sp << endl;             // 10
    cout << sp.get() << endl;        // 0x...aeb0
    cout << sp.use_count() << endl;  // 2
    cout << *sp3 << endl;            // 10
    cout << sp3.get() << endl;       // 0x...aeb0
    cout << sp3.use_count() << endl; // 2

    cout << endl;

    shared_ptr<Point> sp4(new Point(2, 3));
    vector<shared_ptr<Point>> numbers;
    numbers.push_back(shared_ptr<Point>(new Point(1, 2)));
    numbers.push_back(sp4);
    numbers[0]->print();
    numbers[1]->print();
    
    return 0;
}