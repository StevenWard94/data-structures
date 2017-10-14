/**
 * File:        include/Node.hpp
 * Author:      Steven Ward <stevenward94@gmail.com>
 * Last Change: 2017 Oct 13
 */

#ifndef DATA_STRUCTURES_INCLUDE_NODE_HPP_
#define DATA_STRUCTURES_INCLUDE_NODE_HPP_

#include "utilities.hpp"

#include <iostream>

template<typename E>
class Node {

 public:
  using value_t = E;

  inline Node( ) = default;
  inline Node(value_t const& data) : data_{data} { }
  inline Node(value_t&& data) : data_{std::move(data)} { }

  inline Node(value_t const& data, Node* const next_node)
          : data_{data}, next_{next_node} { }

  inline Node(value_t&& data, Node* const next_node)
          : data_{std::move(data)}, next_{next_node} { }

  inline Node(Node const& other) : data_{other.data_}, next_{other.next} { }

  inline Node(Node&& other)
          : data_{std::move(other.data_)}, next_{std::move(other.next_)} { }


 private:
  value_t data_ { };
  Node<value_t>* next_ { };

};

#endif    // DATA_STRUCTURES_INCLUDE_NODE_HPP_
