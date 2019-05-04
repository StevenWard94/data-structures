/***********************************************************************************//**
 * Author:       Steven Ward <stevenward94@gmail.com>
 * File:         data-structures/include/ForwardList.hpp
 * URl:          https://github.com/StevenWard94/data-structures
 * Last Change:  2018 Sep 11
 ***********************************************************************************/

#ifndef DATA_STRUCTURES_INCLUDE_FORWARD_LIST_HPP_
#define DATA_STRUCTURES_INCLUDE_FORWARD_LIST_HPP_

#include "ForwardIterator.hpp"

template<typename E>
class ForwardList {

 public:
  ForwardList( ) = default;

  ForwardList(const Node<E>* head) : head_{head->get(), head->next()}, size_{1} { }
  ForwardList(Node<E>* head) : head_{head}, size_{1} { }

  ForwardList(E&& head_data) : head_{std::move(head_data)}, size_{1} { }
  ForwardList(E const& head_data) : head_{head_data}, size_{1} { }

  ~ForwardList( ) { delete head_; }

  size_t size( ) { return size_; }
  bool empty( ) { return (size_ == 0); }

  void push(E const& data);
  void push(E&& data);

 private:
  Node<E>* head_ { };
  size_t size_ { };



};

#endif    // DATA_STRUCTURES_INCLUDE_FORWARD_LIST_HPP_
