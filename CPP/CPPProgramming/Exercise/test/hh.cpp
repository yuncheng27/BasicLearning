#include <iostream>
using namespace std;
class ArrayMax
{
    public:
    void SetValue();
    void MaxValue();
    void ShowValue();
    private:
    int array[10];
    int max;
};

void ArrayMax::SetValue()
{
    int i;
    for (i = 0; i < 10; i++)
        cin>>array[i];
}

void ArrayMax::MaxValue()
{
    int i;
    max = array[0];
    for (i = 1; i < 10; i++)
        if (array[i] > max) max = array[i];
}

void ArrayMax::ShowValue()
{
    cout << "max="<<max<<endl;
}

int main()
{
    ArrayMax arrmax;
    arrmax.SetValue();
    arrmax.MaxValue();
    arrmax.ShowValue();
    return 0;
}

