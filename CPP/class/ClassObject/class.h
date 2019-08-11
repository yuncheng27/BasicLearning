#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;
struct A
{
	int a[10000];
};

class A1 {
    public:
    void f1(){}
    private:
    int _a;
};

//类中仅有成员函数
class A2 {
    public:
    void f2() {}
};

//空类
class A3
{};
