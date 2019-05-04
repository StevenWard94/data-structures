/***********************************************************************************//**
 * Author:       Steven Ward <stevenward94@gmail.com>
 * File:         data-structures/include/Node.hpp
 * URl:          https://github.com/StevenWard94/data-structures
 * Last Change:  2018 Sep 11
 ***********************************************************************************/

#ifndef DATA_STRUCTURES_INCLUDE_NODE_HPP_
#define DATA_STRUCTURES_INCLUDE_NODE_HPP_

#include <utility>

template<typename E>
class Node {

 public:
  using value_t = E;

  Node( ) = default;
  Node(E&& data) : data_{std::move(data)} { }
  Node(E const& data) : data_{data} { }
  Node(E&& data, Node<E>* next_node) : data_{std::move(data)}, next_{next_node} { }
  Node(E const& data, Node<E>* next_node) : data_{data}, next_{next_node} { }
  ~Node( ) { delete next_; }

  void setData(E const& data) : data_{data} { }
  E const& get( ) const { return data_; }
  E get( ) const { return data_; }

  void setNext(const Node<E>* next_node) : next_{next_node} { }
  const Node<E>* next( ) const { return next_; }
  Node<E>* next( ) const { return next_; }


 private:
  E data_ { };
  Node<E>* next_ { };

};

#endif    // DATA_STRUCTURES_INCLUDE_NODE_HPP_
