#include <iostream>
#include <memory>

using namespace std;

struct FILECloser
{
    void operator()(FILE *fp)
    {
        if (fp)
        {
            fclose(fp);
        }
    }
};

// ptr -- 这是指向要被写入的元素数组的指针。
// size -- 这是要被写入的每个元素的大小，以字节为单位。
// nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
// stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输出流。

void test()
{
    unique_ptr<FILE, FILECloser> up(fopen("a.txt", "a+"));
    string msg = "hello,world\n";
    fwrite(msg.c_str(), 1, msg.size(), up.get());
}

void test2()
{
    shared_ptr<FILE> up(fopen("b.txt", "a+"), FILECloser());
    string msg = "hello,world\n";
    fwrite(msg.c_str(), 1, msg.size(), up.get());
}

void test3()
{
    FILE *test = fopen("c.txt", "a+");
    string msg = "hello,world\n";
    fwrite(msg.c_str(), 1, msg.size(), test);
    fclose(test);
}

int main()
{
    return 0;
}