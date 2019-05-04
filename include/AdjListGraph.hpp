/***********************************************************************************//**
 * Author:       Steven Ward <stevenward94@gmail.com>
 * File:         data-structures/include/AdjListGraph.hpp
 * URl:          https://github.com/StevenWard94/data-structures
 * Last Change:  2019 Mar 12
 ***********************************************************************************/

#ifndef DATA_STRUCTURES_INCLUDE_ADJ_LIST_GRAPH_HPP_
#define DATA_STRUCTURES_INCLUDE_ADJ_LIST_GRAPH_HPP_

#include <utility>
#include <vector>


template <typename T, bool directed = false>
class AdjListGraph {

  // forward declare nested Vertex class as private member type
  class Vertex;

 public:
  using val_type = T;
  using ref_type = val_type&;
  using const_ref_type = val_type const&;

  /**
   *
   */


 private:
  // vector of Vertex objects that describes the set, V(G)
  std::vector<Vertex> vertices_;
  // bool value representing whether G is a digraph - assigned to the value of non-type
  //   template argument, 'directed'
  const bool is_directed_ = directed;

  // definition of the OutEdge nested class
  class OutEdge {
   public:
    OutEdge(size_t end_id, size_t cost) : dest_id(end_id), cost(cost) { }
    size_t get_dest_id( ) const { return dest_id; }
    size_t get_cost( ) const { return cost; }

   private:
    size_t dest_id;
    size_t cost;
  };

  // definition of the Vertex nested class
  class Vertex {
   public:
    Vertex(size_t id, T const& value) : id(id), data{value} { }
    Vertex(size_t id, T&& value) : id(id), data{std::move(id)} { }

   private:
    size_t id;    // unique identifier for the Vertex object
    T data;
    std::vector<OutEdge> outgoing_edges;
  };
};


#endif  // DATA_STRUCTURES_INCLUDE_ADJ_LIST_GRAPH_HPP_
