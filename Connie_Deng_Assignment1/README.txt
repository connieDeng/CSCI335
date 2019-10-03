You will use this exact Makefile for your Homework 1. Failure to do so will result in deduction of points.

To compile on terminal type
  make all

To delete executables and object file type
  make clean

Connie Deng
CSCI335 - Professor: Stamos,Ioannis

class Chain 
  Class chain is a dynamically allocated array consisting:
  array_ which is a pointer to the address of the first element in arr
  size_ holds the size of the arr/chain

i. All parts have been completed
ii. I believe there are some extra new lines in the output
iii.make all to compile and run with ./test_chain < inputFile
iv. will take an inputFile

The chain class contains copy constructors, destructors,copy assignment operator, 
  move constructor, move assignment operator, with some operation overloads
  
For example, to initate a chain of ints called "a" you would use:
  Chain<int> a;

To initiate a chain containing int 7 called d you would use:
  Chain<int> d{7}; 

ReadChain() reads a chain from input
  For example, reading input and creating a chain called a:
    a.ReadChain();

cout <<
  << operation is overloaded to print elements in chain

copy 
  To copy a chain, for instance copying int chain a into chain called c: 
    Chain<int> c{a};
