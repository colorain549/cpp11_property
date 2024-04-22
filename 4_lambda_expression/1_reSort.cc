// sort默认按字典排序
// 按长度升序排序
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
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

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> svec = {"hello", "hi", "goodbye", "bye"};
    cout << "Default version: " << endl;
    printElems(svec);
    // 默认sort:
    cout << "Default sort version(sorted by dict): " << endl;
    sort(svec.begin(), svec.end());
    printElems(svec);
    // sorted by length(small first)
    cout << "Sorted by length(small first): " << endl;
    sort(svec.begin(), svec.end(), isShorter);
    printElems(svec);
    return 0;
}