//向一个文件里输入1000000个随机数

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
const int num = 1000000;

int main()
{
    ofstream file("data");
    int i;
    for (i = 0; i < num; i++)
    {
        file<<rand()<<' ';
        if ((i + 1)%20 == 0)
        file<<endl;
    }
    return 0;
}
