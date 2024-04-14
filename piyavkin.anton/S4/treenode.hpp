#ifndef TREENODE_HPP
#define TREENODE_HPP
#include <functional>
#include <utility>

namespace piyavkin
{
  namespace detail
  {
    template< class Key, class T >
    struct Node
    {
      template< class... Args >
      Node(const Key& key, Node* right, Node* left, Node* parent, Args&& ...args):
        key_(key),
        data_(std::forward< Args >(args)...),
        right_(right),
        left_(left),
        parent_(parent)
      {}
      Key key_;
      T data_;
      Node* right_;
      Node* left_;
      Node* parent_;
    };
  }
}
#endif