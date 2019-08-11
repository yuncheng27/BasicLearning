> 关于字符数组的内容，详见本书p148

#### C++处理字符串的方法——字符串类与字符串变量
> C++提供了一种新的数据类型——字符串类型(string类型)，可以用来定义变量，这就是字符串变量——用一个名字代表一个字符序列

>实际上string并不是C++语言本身具有的基本类型，而是C++标准中声明的一个字符串类，用这种类可以定义对象。每一个字符串变量都是string类的一个对象
> - 字符串变量的定义和引用
```cpp
#include <string>    //必须包含头文件
int main()
{
    string string1;
    string string2 = "China";      //定义并初始化
    string1 = string2;        //可以用字符串变量或变量给另一个字符串变量赋值
    return 0;
}
//说明：字符串常量以'\0'作为结束符，但将字符串常量存放到字符串变量时，只存放字符串本身而不包括'\0'
```
> - 字符串连接使用加号``string1 += string2;``
> - 字符串数组
>   - ``string name[5] = {"zhao", "qian", "sun", "li", "zhou"};``
>   - 在一个字符串数组中包含若干元素，每个元素相当于一个字符串变量
>   - 并不要求每个字符串元素具有相同的长度，即使对于同一个元素而言，其长度也是可以变化的
>   - 在字符串数组的每一个元素中存放一个字符串，而不是一个字符，这是字符串数组与字符数组的区别，一个一维字符数组只能存放一个字符串
>   - 每一个字符串元素中只包含字符串本身的字符而不包括'\0'
>   - 实际上，**编译系统为每一个字符串变量分配4个字节，在这个存储单元中，并不是直接存储字符串本身，而是存放字符串地址**
> 归纳起来，C++对字符串的处理有两种方法：一种是用字符数组的方法，称为C-string方法；一种是string类定义字符串变量，称为string方法。显然后者更好用