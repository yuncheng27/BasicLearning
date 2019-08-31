# include <iostream>

//析构函数的多态
class Person 
{
  public:
    Person() {std::cout << "Person()" << std::endl;};       //构造函数不能为虚函数
    virtual ~Person() {std::cout << "~Person()"<< std::endl;};
};

class Child : public Person 
{
  public:
    Child() {std::cout << "Child()" << std::endl;};
    virtual ~Child() {std::cout << "~Child()" << std::endl;};
};

void Test()
{
  Person* p1 = new Person;  //直接调用Person()
  Person* p2 = new Child;   //先调用Person(), 再调用Child()
  delete p1;   //直接调用~Person()
  delete p2;   //先调用~Child(), 再调用~Person()
}


#if 0
//协变：重写虚函数的返回值可以不同，但必须分别是基类指针和派生类指针或者基类引用或者派生类引用
class A{};
class B : public A{};

class Person 
{
  public:
    virtual A* f() {return new A;};
};

class Child : public Person 
{
  public:
    virtual B* f() {return new B;};
};
#endif

#if 0
//多态：买火车票

class Parent 
{
  public:
    virtual void BuyTicket(){
      std::cout << "买票全价" << std::endl;
    }
};

class Child : public Parent 
{
  public:
    virtual void BuyTicket() {
      std::cout << "买票半价" << std::endl;
    }
};

void Func(Parent &people)
{
  people.BuyTicket();
}

void Test()
{
  Parent p;
  Child c;
  Func(p);
  Func(c);
}
#endif


int main()
{
  Test();
  return 0;
}
