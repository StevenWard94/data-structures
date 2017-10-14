/**
 * File:        include/utilities.hpp
 * Author:      Steven Ward <stevenward94@gmail.com>
 * Last Change: 2017 Oct 13
 */


#ifndef DATA_STRUCTURES_UTILS_INCLUDE_UTILITIES_HPP_
#define DATA_STRUCTURES_UTILS_INCLUDE_UTILITIES_HPP_


#include <type_traits>
#include <utility>

namespace utils {

template<class ...> using void_t = void;

template<class Type>
using remove_reference = typename std::remove_reference<Type>::type;

template<class Predicate, class Param = void>
using enable_if = typename std::enable_if<Predicate::value, Param>::type;

template<class Predicate, class Param = void>
using disable_if = typename std::enable_if<!Predicate::value, Param>::type;


template<typename Type, typename = void>
struct EqClass : std::false_type { };

template<typename Type>
struct EqClass< Type, void_t<decltype( std::declval<Type>() == std::declval<Type>() )> >
              : std::true_type { };


template<typename Type, typename = void>
struct OrdClass : std::false_type { };

template<typename Type>
struct OrdClass< Type, void_t<decltype( std::declval<Type>() < std::declval<Type>() )> >
               : std::true_type { };


template<typename DataType>
using is_Eq_instance = typename EqClass<DataType>::value;

template<typename DataType>
using is_Ord_instance = typename OrdClass<DataType>::value;

}


#endif    // DATA_STRUCTURES_UTILS_INCLUDE_UTILITIES_HPP_
