#include<iostream>
#include<ctime>
#include<cstdio>
#include<unistd.h>
using namespace std;
const int num = 1000;
std::ios::sync_with_stdio(false);
int main()
{
    freopen("data", "r", stdin);
    int i, n, start, end;
    start = clock();
    for (i = 0; i < num - 2; i++)
    cin>>n;
    end = clock();
    //cout<<float(end - start)/CLOCKS_PER_SEC<<endl;
    cout<<end - start<<endl;
    sleep(1);
    return 0;
}
