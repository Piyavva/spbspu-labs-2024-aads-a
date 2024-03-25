#ifndef NODE_HPP
#define NODE_HPP

namespace piyavkin
{
  namespace detail
  {
    template< class T >
    struct Node
    {
      Node(const T& value = T(), Node* next = nullptr, Node* prev = nullptr):
        value_(value),
        next_(next),
        prev_(prev)
      {}
      ~Node() = default;
      T value_;
      Node* next_;
      Node* prev_;
    };
  }
}
#endif