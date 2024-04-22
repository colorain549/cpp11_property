// 循环引用
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// 前置声明
class Child;
class Parent
{
public:
    Parent()
    {
        cout << "Parent()" << endl;
    }
    ~Parent()
    {
        cout << "~Parent()" << endl;
    }

    weak_ptr<Child> pParent;
};

class Child
{
public:
    Child()
    {
        cout << "Child()" << endl;
    }
    ~Child()
    {
        cout << "~Child()" << endl;
    }

    shared_ptr<Parent> pChild;
};

int main()
{
    // 循环引用可能导致内存泄漏
    shared_ptr<Parent> parentPtr(new Parent());
    shared_ptr<Child> childPtr(new Child());
    // cout << parentPtr.use_count() << endl;
    // cout << childPtr.use_count() << endl;

    parentPtr->pParent = childPtr;
    childPtr->pChild = parentPtr;
    // cout << parentPtr.use_count() << endl;
    // cout << childPtr.use_count() << endl;

    return 0;
}
