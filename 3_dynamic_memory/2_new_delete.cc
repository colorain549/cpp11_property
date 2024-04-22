// 动态内存
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int *getInput(int arg)
{
    return new int(arg);
}

int main()
{
    int n = 2;
    int *p = getInput(n);
    cout << *p << endl;
    delete p;
    return 0;
}