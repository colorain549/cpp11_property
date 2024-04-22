#include <iostream>
#include <functional>

using std::bind;
using std::cin;
using std::cout;
using std::endl;
using namespace std::placeholders;

int f(int a, int b)
{
    return a + b;
}

int main()
{
    auto it = bind(f, _1, 8);
    auto ret = f(1, 2);

    // int a = 97;
    // int b = 98;
    // int c = 99;
    // auto it = bind(f, a, b, _2, c, _1);
    cout << ret << endl;

    return 0;
}