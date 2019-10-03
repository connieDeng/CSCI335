//Connie Deng
// Place comments describing the class Chain (two lines).

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_

#include <iostream>
#include <cstddef>
#include <vector>
#include <string>
#include <sstream>

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Chain {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  Chain(){
    size_ = 0;
    array_ = nullptr; //points to null
  };

  // Copy-constructor.
  Chain(const Chain &rhs){
    size_ =  rhs.size();
    array_ = Object ch[size_];
    std::cout << size_;
    for(int i = 0 ; i < size_; i++){
      array_[i] = rhs[i];
    }
    
  };

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Chain copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Chain& operator=(const Chain &rhs) = default;

  // Move-constructor. 
  Chain(Chain &&rhs) = default;

  // Move-assignment.
  // Just use std::swap() for all variables.
  Chain& operator=(Chain &&rhs) = default;

  ~Chain() {
    // Provide destructor.
  }

/*          End of big-five.              */

  // One parameter constructor.
  //point to address of first element in array
  Chain(const Object& item) {
    size_ = 1;
    Object ch[size_]; //makes array of Objects
    ch[0] = item;
    array_ = ch;   //array points to address of ch[0]
  }

  // Read a chain from standard input.
  void ReadChain() {
    Object obj;
  }

  size_t size() const { 
    return size_;
  }

  // @location: an index to a location in the chain.
  // @returns the Object at @location.
  // const version.
  // abort() if out-of-range.
  const Object& operator[](size_t location) const { 
    if(location > size_ || location < 0){
      abort();
    }
    return array_[location]; 
  }

 // @location: an index to a location in the range.
 // @returns the Object at @location.
 // non-const version.
 // abort() if out-of-range.
 Object& operator[](size_t location) { 
   // Write something (will be the same as above)
 }

 //  @c1: A chain.
 //  @c2: A second chain.
 //  @return the concatenation of the two chains.
 friend Chain operator+(const Chain &c1, const Chain &c2) {
  // Write something.
 }

 //global operator function is made riend of this class so
 //it can access private members
 // Overloading the << operator.
 //&: takes chain by reference
 friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
  out << "[";
   for(int i = 0; i < a_chain.size(); i++){      
      out << a_chain[i];
    }
   // return std::ostream so we can chain calls to operator<<
   out << "]";
   return out;
 }
 
 private:
  size_t size_;
  Object *array_; //pointer to first element in array
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
