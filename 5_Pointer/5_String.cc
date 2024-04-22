#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    // 构造函数
    String(char *pstr) : _pstr(new char[strlen(pstr) + 1])
    {
        cout << "构造函数 String(char *pstr)" << endl;
        strcpy(_pstr, pstr);
    }

    // 拷贝构造函数
    String(const String &rhs) : _pstr(new char[strlen(rhs._pstr) + 1])
    {
        cout << "拷贝构造函数 String(const String &rhs)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    // 移动构造函数(右值引用作为参数):列表初始化
    String(String &&rhs) : _pstr(rhs._pstr)
    {
        cout << "移动构造函数 String(String &&rhs)" << endl;
        rhs._pstr = nullptr;
    }

    // 移动赋值运算符函数
    String &operator=(String &&rhs)
    {
        cout << "移动赋值运算符函数 String &operator=(String &&rhs)" << endl;
        // 自复制
        if (this != &rhs)
        {
            // 释放左操作数
            delete[] _pstr;
            _pstr = nullptr;
            // 转移右操作数的资源
            _pstr = rhs._pstr;
            // 右操作数置为空
            rhs._pstr = nullptr;
        }
        return *this;
    }

    // 析构函数
    ~String()
    {
        if (_pstr)
        {
            cout << "析构函数 delete[] _pstr;" << endl;
            delete[] _pstr;
        }
    }

    // 重载<<运算符
    friend ostream &operator<<(ostream &os, const String &s);

private:
    char *_pstr;
};

// 重载 << 运算符以输出 String 对象
ostream &operator<<(ostream &os, const String &s)
{
    os << s._pstr;
    return os;
}

String &&rightValue()
{
    return "test";
}

int main()
{
    // 构造函数
    String s1("s1");
    cout << s1 << endl;

    // 拷贝构造函数
    String s2(s1);
    cout << s2 << endl;

    // 构造函数 + 赋值
    // String s3 = String("s3");
    // cout << s3 << endl;

    // 移动构造函数
    String s3(std::move(s1));
    cout << s3 << endl;

    // 移动赋值运算符函数
    // s1 = std::move(s3);

    // std::move(s3)将s3转换为右值
    // 并将其资源移动给s1
    // 调用移动赋值运算符
    // s1资源释放
    // 转移s3的资源
    // s3的状态不可预测

    return 0;
}
