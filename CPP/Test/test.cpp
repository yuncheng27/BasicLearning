#include <iostream>
#include <sstream>

int main()
{
  std::string a = "2019-01-01";
  std::string[] b = a.split("-");
  std::cout << b[0] << ","<< b[1] <<","<< b[2] <<std::endl;
  return 0;
}
