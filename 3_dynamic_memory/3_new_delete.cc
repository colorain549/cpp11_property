// 动态内存
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void getInput2(int arg)
{
    int *p = new int(arg);
    cout << *p << endl;
    delete p;
}

int main()
{
    int n = 2;
    getInput2(n);
    return 0;
}