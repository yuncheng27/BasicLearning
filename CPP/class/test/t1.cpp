#include<iostream>
using namespace std;

int max(int a,int b)
{
        return a>=b?a:b;
}

double max(double a,double b)
{
        return a>=b?a:b;
}
int main()
{
    cout<<"max int is: "<<max(1,3)<<endl;
    cout<<"max double is: "<<max(1.2,1.3)<<endl;
    return 0;
}
