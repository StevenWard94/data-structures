/***********************************************************************************//**
 * Author:       Abdullah Ozturk <https://medium.com/@aozturk>
 * Original:     https://github.com/aozturk/HashMap
 * Maintainer:   Steven Ward <stevenward94@gmail.com>
 * File:         data-structures/NaiveHashMap/naivehashmap/HashNode.hpp
 * URl:          https://github.com/StevenWard94/data-structures
 * Last Change:  2019 Apr 18
 ***********************************************************************************/

/**
 * Copyright 2019 Steven Ward <stevenward94@gmail.com>
 *
 * Copyright 2017 HashMap Development Team
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * This file has been edited as part of a learning experience for a
 * Computer Science Undergraduate student and to make updates for
 * C++11 and for optimization.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef DATA_STRUCTURES_INCLUDE_HASH_NODE_HPP_
#define DATA_STRUCTURES_INCLUDE_HASH_NODE_HPP_

#include <utility>

template <typename K, typename V>
class HashNode {
 public:
  using key_type = K;
  using value_type = V;

  HashNode(key_type const& key, value_type const& value) :
           key_{key}, value_{value} { }
  HashNode(key_type const& key, value_type&& value) :
           key_{key}, value_{std::move(value)} { }
  HashNode(key_type&& key, value_type const& value) :
           key_{std::move(key)}, value_{value} { }
  HashNode(key_type&& key, value_type&& value) :
           key_{std::move(key)}, value_{std::move(value)} { }

  key_type getKey( ) const { return key_; }
  value_type getValue( ) const { return value_; }

  void setValue(value_type const& value) { value_ = value; }
  void setValue(value_type&& value) { value_= std::move(value); }

  HashNode* getNext( ) const { return next_; }
  void setNext(HashNode* next) { next_ = next; }

  HashNode(HashNode const& ) = delete;
  HashNode& operator=(HashNode const& ) = delete;

 private:
  key_type key_;
  value_type value_;
  // next node with the same key
  HashNode* next_{nullptr};
};

#endif  //DATA_STRUCTURES_INCLUDE_HASH_NODE_HPP_
