/***********************************************************************************//**
 * Author:       Abdullah Ozturk <https://medium.com/@aozturk>
 * Original:     https://github.com/aozturk/HashMap
 * Maintainer:   Steven Ward <stevenward94@gmail.com>
 * File:         data-structures/NaiveHashMap/naivehashmap/KeyHash.hpp
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

#ifndef DATA_STRUCTURES_INCLUDE_KEY_HASH_HPP_
#define DATA_STRUCTURES_INCLUDE_KEY_HASH_HPP_

#include <stddef.h>

// class template for NaiveHashMap's default hash function parameter ('typename F')
template <typename K, size_t HashSize>
struct KeyHash {
  using key_type = K;
  using ulong = unsigned long;
  // NOTE: this default function is only well-defined for key types that can reasonably
  // be converted to a long unsigned integer. Non-integer type keys are not guaranteed
  // to work properly and the implementation should define a more suitable has function.
  // This default hash function DOES NOT PROVIDE ANY FORM OF COLLISION RESOLUTION!
  ulong operator()(key_type const& key) const {
    return reinterpret_cast<ulong>(key) % HashSize;
  }
};

#endif  //DATA_STRUCTURES_INCLUDE_KEY_HASH_HPP_
