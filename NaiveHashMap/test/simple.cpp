/***********************************************************************************//**
 * Author:       Abdullah Ozturk <https://medium.com/@aozturk>
 * Original:     https://github.com/aozturk/HashMap
 * Maintainer:   Steven Ward <stevenward94@gmail.com>
 * File:         data-structures/NaiveHashMap/test/simple.cpp
 * URl:          https://github.com/StevenWard94/data-structures
 * Last Change:  2019 Apr 18
 ***********************************************************************************/

#ifdef CUSTOMDEBUG
#define DEBUG_OUT(x) x
#else
#define DEBUG_OUT(x)
#endif


#include <iostream>
#include <assert.h>

#include "../naivehashmap/NaiveHashMap.hpp"


struct MyKeyHash {
  unsigned long operator()(int key) const {
    return key % 10;
  }
};


int main() {

  DEBUG_OUT(std::cerr << "Construct NaiveHashMap\n"
                      << "\t\t<key_type = int, value_type = std::string, SIZE = 10\n"
                      << "\t\t hash_fn = MyKeyHash{ operator()(int k){return key % 10;} }> . . .\n";)
  NaiveHashMap<int, std::string, 10, MyKeyHash> hmap;
  DEBUG_OUT(std::cerr << ". . . SUCCESS!\n" << std::string(50, '-') << std::endl;)
  DEBUG_OUT(std::cerr << "Put {1,\"one\"}, {2,\"two\"}, {3,\"three\"} in NaiveHashMap . . .\n";)
  hmap.put(1, "one");
  hmap.put(2, "two");
  hmap.put(3, "three");
  DEBUG_OUT(std::cerr << ". . . SUCCESS!\n" << std::string(50, '-') << std::endl;)

  std::string value;
  DEBUG_OUT(std::cerr << "Attempt NaiveHashMap::get(2, value&) . . .\n";)
  bool result = hmap.get(2, value);
  assert(result);
  assert(value == "two");
  DEBUG_OUT(std::cerr << ". . . result == true . . . value == \"two\" . . . SUCCESS!\n"
            << std::string(50, '-') << std::endl;)

  DEBUG_OUT(std::cerr << "Attempt NaiveHashMap::get(3, value&) . . .\n";)
  result = hmap.get(3, value);
  assert(result);
  assert(value == "three");
  DEBUG_OUT(std::cerr << ". . . result == true . . . value == \"three\" . . . SUCCESS!\n"
            << std::string(50, '-') << std::endl;)

  DEBUG_OUT(std::cerr << "Attempt NaiveHashMap::remove(3) . . .\n";)
  hmap.remove(3);
  DEBUG_OUT(std::cerr << "Attempt NaiveHashMap::get(3, value&) . . .\n";)
  result = hmap.get(3, value);
  assert(!result);
  DEBUG_OUT(std::cerr << ". . . result == false . . . SUCCESS!\n";)
}
