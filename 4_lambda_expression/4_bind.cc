// 标准库bind函数
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::bind;
using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::string;
using std::vector;
// using std::placeholders::_1;
using namespace std::placeholders;

void printElems(vector<string> svec)
{
    for (auto &elem : svec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

bool check_size(const string &s, string::size_type len)
{
    return s.size() <= len;
}

int main()
{
    vector<string> svec = {"hello", "hi", "goodbye", "bye"};
    cout << "Default version: " << endl;
    printElems(svec);
    //
    // 使用find_if结合lambda表达式
    // int len = 2;
    // auto it = find_if(svec.begin(), svec.end(), [len](const string &a)
    //                   { return a.size() <= len; });
    //
    // bind生成一个新的 可调用对象 来适应 原对象的参数列表
    auto it = find_if(svec.begin(), svec.end(), bind(check_size, _1, 2));
    cout << "Length less than or equal to 2: " << endl;
    cout << *it << endl;
    return 0;
}