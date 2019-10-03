// Connie Deng
// class Chain is a dynamically allocated array consisting:
//    array_ which is a pointer to the address of the first element in arr
//    size_ holds the size of the arr/chain

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_

#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
// The chain class contains copy constructors, destructors,copy assignment operator, 
// move constructor, move assignment operator, with some operation overloads
// sample use case initalization: Chain<int> a;
template<typename Object>
class Chain {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  Chain(){
    size_ = 0;
    array_ = nullptr;
  }

  // Copy-constructor.
  //rhs passed by reference
  Chain(const Chain &rhs){
    //std::cout<< "is this wrong";
    size_ = rhs.size_;
    //array_ = rhs.array_;
    //array_ = new Object{ *rhs.array_ };
    array_ = new Object[size_];
    for(int i = 0; i < rhs.size_; i++){
      array_[i] = rhs.array_[i];
    }
  }

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Chain copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Chain& operator=(const Chain &rhs){
    Chain copy = rhs; 
    std::swap(*this, copy);
    return *this;
  }

  // Move-constructor. 
  Chain(Chain &&rhs){
    size_ = rhs.size_;
    array_ = rhs.array_;
    rhs.array_ = nullptr;
    rhs.size_ = 0;
    /*
    this->size_ = rhs.size_;
    rhs.array_ = nullptr;
    rhs.size_ = 0;*/
  }

  // Move-assignment.
  // Just use std::swap() for all variables.
  Chain& operator=(Chain &&rhs){
    //Object copy = rhs;
    //std::cout << "move assignment";
    //this->size_ = rhs.size_;
    std::swap(array_, rhs.array_);
    std::swap(size_, rhs.size_);
    rhs.size_ = 0;
    rhs.array_ = nullptr;
    return *this;
  }

  ~Chain() {
    // Provide destructor.
    size_ = 0;
    delete [] array_;
  }

  // End of big-five.

  // One parameter constructor.
  Chain(const Object& item) {
    size_ = 1;
    array_ =new Object [size_];
    array_[0] = item;
  }

  // Read a chain elementfrom standard input.
  void ReadChain() {    
    std::string str;
    getline(std::cin, str);

    str.erase(0,1); //delete [
    str.pop_back(); //delete ]
    
    std::stringstream ss(str);

    ss >> size_;

    //std::cout << size_ << std::endl;

    Object convert_;
    array_ = new Object[size_]; 
    char ch = ss.get(); //extracts single char from string

    for(int i = 0; i < size_; i++){
      ss >> convert_;
      array_[i] = convert_;
    }
  }

  size_t size() const { // Write something
    return size_;
  }

  // @location: an index to a location in the chain.
  // @returns the Object at @location.
  // const version.
  // abort() if out-of-range.
  const Object& operator[](size_t location) const { 
      if(location > size_ || location < 0)
    abort();
  else
    return array_[location];
  }

 // @location: an index to a location in the range.
 // @returns the Object at @location.
 // non-const version.
 // abort() if out-of-range.
 Object& operator[](size_t location) { 
  if(location > size_ || location < 0)
    abort();
  else
    return array_[location];
 }

 //  @c1: A chain.
 //  @c2: A second chain.
 //  @return the concatenation of the two chains.
 friend Chain operator+(const Chain &c1, const Chain &c2) {
   Chain ch;
   //std::cout << c1.size_ << " " << c2.size_;
   int total = c1.size() + c2.size();
   //ch.size_ = c1.size_ + c2.size_;
   ch.size_ = total;
   ch.array_ = new Object[total];
   int index = 0;
   while(index < ch.size_){
      for(int i = 0; i < c1.size_ ; i++){
        ch.array_[index] = c1.array_[i];
        index++;
      }

      for(int j = 0; j < c2.size_ ; j++){
        ch.array_[index] = c2.array_[j];
        index++;
      }
   }
   return ch;
 }

//plus overload adding an element
 friend Chain operator+(const Chain &c1, Object x) {
   //std:: cout<< "reached here"; 
   Chain ch;
   int total = c1.size() + 1;
   ch.size_ = total;
   ch.array_ = new Object[total];
   int index = 0;
   while(index < ch.size_){
      for(int i = 0; i < c1.size_ ; i++){
        ch.array_[index] = c1.array_[i];
        index++;
      }
      ch.array_[index] = x;
      index++;
   }
   return ch;
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
   // Print the chain.
   if(a_chain.size_ == 0){
     out << "[]" << std::endl;
     return out;
   }
  
  else{
   int counter = a_chain.size_-1;
   out << "[";
   for(int i = 0; i < a_chain.size(); i++){
     out << a_chain[i];
     if(counter > 0){
       out << " ";
       counter--;
     }
   }
   out << "]" << std::endl;
   return out;
  }
 }
 
 private:
  size_t size_;
  Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
