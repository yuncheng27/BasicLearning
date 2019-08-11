#include <iostream>
#include <memory>

struct ListNode
{
  int _data;
  std::weak_ptr<ListNode> _prev;
  std::weak_ptr<ListNode> _next;

  ~ListNode(){std::cout << "~ListNode()" << std::endl;};
};

int main()
{
  std::shared_ptr<ListNode> node1(new ListNode);
  std::shared_ptr<ListNode> node2(new ListNode);
  std::cout << node1.use_count() << std::endl;
  std::cout << node2.use_count() << std::endl;

  node1->_next = node2;
  node2->_prev = node1;

  std::cout << node1.use_count() << std::endl;
  std::cout << node2.use_count() << std::endl;
  return 0;
}
