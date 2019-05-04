/***********************************************************************************//**
 * Author:       Abdullah Ozturk <https://medium.com/@aozturk>
 * Original:     https://github.com/aozturk/HashMap
 * Maintainer:   Steven Ward <stevenward94@gmail.com>
 * File:         data-structures/NaiveHashMap/naivehashmap/NaiveHashMap.hpp
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

#ifndef DATA_STRUCTURES_INCLUDE_NAIVE_HASH_MAP_HPP_
#define DATA_STRUCTURES_INCLUDE_NAIVE_HASH_MAP_HPP_

#include "HashNode.hpp"
#include "KeyHash.hpp"

#include <stdexcept>
#include <string>
#include <type_traits>


template < typename K, typename V, size_t SIZE, typename F = KeyHash<K, SIZE> >
class NaiveHashMap {
 public:
  using key_type = K;
  using value_type = V;
  using fn_type = F;

  NaiveHashMap( ) : table_{ }, hash_function_{ } { }
  NaiveHashMap(NaiveHashMap const& ) = delete;
  NaiveHashMap& operator=(NaiveHashMap const& ) = delete;


  ~NaiveHashMap( ) {
    // delete each element in the hash map table
    for (size_t i = 0; i < SIZE; i++) {
      HashNode<key_type, value_type>* item = table_[i];

      while (item != nullptr) {
        HashNode<key_type, value_type>* next_item = item->getNext();
        delete item;
        item = next_item;
      }
      table_[i] = nullptr;
    }
  }


  bool get(key_type const& key, value_type& value) {
    ulong hashResult = hash_function_(key);
    HashNode<key_type, value_type>* item = table_[hashResult];

    while (item != nullptr) {
      if (item->getKey() == key) {
        value = item->getValue();
        return true;
      }
      item = item->getNext();
    }
    return false;
  }


/**
  value_type& get(key_type const& key) {
    value_type* value_ptr = nullptr;
    this->has(key, value_ptr);
    if (value_ptr != nullptr) {
      return *value_ptr;
    }
    else {
      std::string err_msg = "NaiveHashMap::get(): Key";
      if (std::is_convertible<key_type,std::string>::value) {
        err_msg += ": ";
        err_msg += key;
      }
      err_msg += " not found in Hash Map.";
      throw std::out_of_range(err_msg);
    }
  }
  */


  void put(key_type const& key, value_type const& value) {
    ulong hashResult = hash_function_(key);
    HashNode<key_type, value_type>* prev = nullptr;
    HashNode<key_type, value_type>* item = table_[hashResult];

    while (item != nullptr && item->getKey() != key) {
      prev = item;
      item = item->getNext();
    }

    if (item == nullptr) {
      item = new HashNode<key_type, value_type>(key, value);

      if (prev == nullptr) {
        // this entry is the first at table_[hashResult]
        table_[hashResult] = item;
      }
      else {
        // this entry is not the first at table_[hashResult]
        prev->setNext(item);
      }
    }
    else {
      // assign 'value' to this new entry
      item->setValue(value);
    }
  }


/**
  void put(key_type const& key, value_type&& value) {
    ulong hashResult = hash_function_(key);
    HashNode<key_type, value_type>* prev = nullptr;
    HashNode<key_type, value_type>* item = table_[hashResult];

    while (item != nullptr && item->getKey() != key) {
      prev = item;
      item = item->getNext();
    }

    if (item == nullptr) {
      item = new HashNode<key_type, value_type>(key, std::forward(value));

      if (prev == nullptr) {
        // this entry is the first at table_[hashResult]
        table_[hashResult] = item;
      }
      else {
        // this entry is not the first at table_[hashResult]
        prev->setNext(item);
      }
    }
    else {
      // assign 'value' to this new entry
      item->setValue(std::forward(value));
    }
  }



  void put(key_type&& key, value_type const& value) {
    ulong hashResult = hash_function_(key);
    HashNode<key_type, value_type>* prev = nullptr;
    HashNode<key_type, value_type>* item = table_[hashResult];

    while (item != nullptr && item->getKey() != key) {
      prev = item;
      item = item->getNext();
    }

    if (item == nullptr) {
      item = new HashNode<key_type, value_type>(std::forward(key), value);

      if (prev == nullptr) {
        // this entry is the first at table_[hashResult]
        table_[hashResult] = item;
      }
      else {
        // this entry is not the first at table_[hashResult]
        prev->setNext(item);
      }
    }
    else {
      // assign 'value' to this new entry
      item->setValue(value);
    }
  }


  void put(key_type&& key, value_type&& value) {
    ulong hashResult = hash_function_(key);
    HashNode<key_type, value_type>* prev = nullptr;
    HashNode<key_type, value_type>* item = table_[hashResult];

    while (item != nullptr && item->getKey() != key) {
      prev = item;
      item = item->getNext();
    }

    if (item == nullptr) {
      item = new HashNode<key_type, value_type>(std::forward(key), std::forward(value));

      if (prev == nullptr) {
        // this entry is the first at table_[hashResult]
        table_[hashResult] = item;
      }
      else {
        // this entry is not the first at table_[hashResult]
        prev->setNext(item);
      }
    }
    else {
      // assign 'value' to this new entry
      item->setValue(std::forward(value));
    }
  }
*/


  bool remove(key_type const& key) {
    ulong hashResult = hash_function_(key);
    HashNode<key_type, value_type>* prev = nullptr;
    HashNode<key_type, value_type>* item = table_[hashResult];

    while (item != nullptr && item->getKey() != key) {
      prev = item;
      item = item->getNext();
    }

    if (item == nullptr) {
      // key not found
      return false;
    }
    else {
      if (prev == nullptr) {
        // remove first item stored at table_[hashResult]
        table_[hashResult] = item->getNext();
      }
      else {
        // remove matching item stored at table_[hashResult]
        prev->setNext(item->getNext());
      }
      delete item;
      item = nullptr;
    }
    return true;
  }


 private:
  using ulong = unsigned long;

  HashNode<key_type, value_type>* table_[SIZE];
  fn_type hash_function_;

  void has(key_type const& key, value_type* value_ptr) {
    ulong hash_value = hash_function_(key);
    HashNode<key_type, value_type>* node_ptr = table_[hash_value];

    while (node_ptr != nullptr) {
      if (node_ptr->getKey() == key) {
        value_ptr = &(node_ptr->getValue());
        break;
      }
      node_ptr->getNext();
    }
  }
};

#endif  //DATA_STRUCTURES_INCLUDE_NAIVE_HASH_MAP_HPP_
