// make_shared函数
#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

int main()
{
    // 指向一个值为42的int的shared_ptr
    shared_ptr<int> p3 = make_shared<int>(42);
    cout << *p3 << endl;

    // 指向一个值为"hello"的string
    shared_ptr<string> p4 = make_shared<string>("hello");
    cout << *p4 << endl;

    // 指向一个值初始化的int
    shared_ptr<int> p5 = make_shared<int>();
    cout << *p5 << endl;

    // 使用auto定义一个对象来保存结果
    // 如何初始化???
    auto p6 = make_shared<vector<string>>();

    return 0;
}