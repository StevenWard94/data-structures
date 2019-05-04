/***********************************************************************************//**
 * Author:       Abdullah Ozturk <https://medium.com/@aozturk>
 * Original:     https://github.com/aozturk/HashMap
 * Maintainer:   Steven Ward <stevenward94@gmail.com>
 * File:         data-structures/NaiveHashMap/test/complex.cpp
 * URl:          https://github.com/StevenWard94/data-structures
 * Last Change:  2019 Apr 18
 ***********************************************************************************/

#ifdef CUSTOMDEBUG
#define DEBUG_OUT(x) x
#else
#define DEBUG_OUT(x)
#endif


#include <iostream>
#include <cmath>
#include <assert.h>
#include <inttypes.h>

#include "../naivehashmap/NaiveHashMap.hpp"


class Param {

 public:
  enum Type {
    FLOAT = 0,
    INT = 1,
  };

  using DictType = NaiveHashMap< char const* , Param* , 8, KeyHash<char const* , 8> >;

  union Value {
    static Value fromInt(int val) {
      Value v;
      v.i = val;
      return v;
    }
    static Value fromFloat(float val) {
      Value v;
      v.f = val;
      return v;
    }
    int i;
    float f;
  };

  template <typename T>
  Param(char const* name, T defaultValue, Type type) :
      def_( ), type_(type) {
        if (type == FLOAT) {
          def_ = Value::fromFloat(float(defaultValue));
        }
        else if (type == INT) {
          def_ = Value::fromInt(int(defaultValue));
        }
        getDict().put(name, this);
      }

  Type getType( ) {
    return reinterpret_cast<Type>(type_);
  }

  int getInt( ) {
    if (getType() == FLOAT) {
      return static_cast<int>(def_.f);
    }
    else if (getType() == INT) {
      return def_.i;
    }
    else {
      return 0;
    }
  }

  float getFloat( ) {
    if (getType() == FLOAT) {
      return def_.f;
    }
    else if (getType() == INT) {
      return static_cast<int>(def_.f);
    }
    else {
      return 0;
    }
  }

  static DictType& getDict( ) {
    return dict_;
  }

 private:
  static DictType dict_;
  Value def_;
  Type type_;

  Param(Param const& p);
  Param& operator=(Param const& p);
};
Param::DictType Param::dict_;


Param p1("param1", 1.0f, Param::FLOAT);
Param p2("param2", 2, Param::INT);
Param p3("param3", 1.3f, Param::FLOAT);


int main() {

  Param* p = nullptr;
  bool result = false;

  // display size of structure
  std::cout << "size of Param: " << sizeof(Param) << std::endl;

  // param1
  result = Param::getDict().get("param1", p);
  assert(result);
  assert(p->getType() == Param::FLOAT);
  assert(fabs(p->getFloat() - 1.0f) < 1e-20);
  assert(p->getInt() == 1);

  // param2
  result = Param::getDict().get("param2", p);
  assert(result);
  assert(p->getType() == Param::INT);
  assert(fabs(p->getFloat() - 2.0f) < 1e-20);
  assert(p->getInt() == 2);

  // param3
  result = Param::getDict().get("param3", p);
  assert(result);
  assert(p->getType() == Param::FLOAT);
  assert(fabs(p->getFloat() - 1.3f) < 1e-20);
  assert(p->getInt() == 1);
}
