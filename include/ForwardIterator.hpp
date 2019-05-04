/***********************************************************************************//**
 * Author:       Steven Ward <stevenward94@gmail.com>
 * File:         data-structures/include/ForwardIterator.hpp
 * URl:          https://github.com/StevenWard94/data-structures
 * Last Change:  2018 Sep 11
 ***********************************************************************************/

#ifndef DATA_STRUCTURES_INCLUDE_FORWARD_ITERATOR_HPP_
#define DATA_STRUCTURES_INCLUDE_FORWARD_ITERATOR_HPP_

#include <stddef.h>
#include <iterator>
#include "Node.hpp"

template<typename E>
class ForwardIterator {

 public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = E;
  using difference_type = ptrdiff_t;
  using pointer = E*;
  using reference = E&;

  ForwardIterator( ) = default;
  explicit ForwardIterator(Node<E>* node) : current{node} { }

  reference operator*( ) const {
    return current->get();
  }

  ForwardIterator& operator++( ) {
    current = current->next();
    return *this;
  }

  ForwardIterator operator++(int) {
    tmp = *this;
    current = current->next();
    return tmp;
  }

  ForwardIterator& operator--( ) = delete;
  ForwardIterator operator--(int) = delete;

  bool operator==(ForwardIterator const& rhs) {
    return (*this == *rhs);
  }

  bool operator!=(ForwardIterator const& rhs) {
    return !(this == rhs);
  }

 private:
  Node<E>* current { };

};

#endif    // DATA_STRUCTURES_INCLUDE_FORWARD_ITERATOR_HPP_
