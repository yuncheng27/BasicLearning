#include <iostream>
#include <vector>

template <class T>
struct S {
  std::vector<T> v;
  S(std::initializer_list<T> l) : v(l) {
    std::cout << "constructed with a " << l.size() << "-element list\n";
  }
  void append(std::initializer_list<T> l) {
    v.insert(v.end(), l.begin(), l.end());
  }
  std::pair<const T*, std::size_t> c_arr() const {
    return {&v[0], v.size()};
  } 
};

template <class T>
void templated_fn(T) {}


