// 使用带参数的lambda表达式
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::string;
using std::vector;

void printElems(vector<string> svec)
{
    for (auto &elem : svec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> svec = {"hello", "hi", "goodbye", "bye"};
    cout << "Default version: " << endl;
    printElems(svec);
    //
    int len = 2;
    auto it = find_if(svec.begin(), svec.end(), [len](const string &a)
                      { return a.size() <= len; });
    cout << "Length less tahn or equal to 2: " << endl;
    cout << *it << endl;
    return 0;
}