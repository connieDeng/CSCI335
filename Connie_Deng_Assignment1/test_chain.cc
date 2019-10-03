// Do not change this file other than adding header files
// if needed.
// You can also comment parts of the functions, and uncomment
// as you add more functionality.
#include <chain.h>
#include <iostream>
#include <string>
#include <fstream>     
using namespace std;
using namespace teaching_project;

// Place stand-alone function in unnamed namespace.
namespace {
void TestPart1() {
    Chain<int> a, b;  // Two empty Chains are created   
    cout << a.size() << " " << b.size() << endl; // yields 0 0
    Chain<int> d{7};  // A chain containing 7 should be created.
    cout << d;  // Should just print [7]
    a.ReadChain(); // User enters a chain, for example [4: 10 30 -1 2]
    cout << a;  // Output should be what user entered.
    b.ReadChain();  // Same for b.
    cout << b;                  
    Chain<int> c{a};  // Calls copy constructor for c.
    cout << c;
    cout << a;
    a = b;  // Should call the copy assignment operator for a.
    cout << a;  
    Chain<int> e = move(c);  // Move constructor for d.
    cout << e;
    cout << c;
    a = move(e);  // Move assignment operator for a.
    cout << a;
    cout << e;
}  

void TestPart2() {
    Chain<string> a, b;
    a.ReadChain();  // User provides input for Chain a.
    cout << a;
    b.ReadChain();  // User provides input for Chain b.
    cout << b << endl;    
    cout << a + b << endl; // Concatenates the two Chains.        
    Chain<string> d = a + b;
    cout << d;
    cout << d + "hi_there";  // Adds an element to the end.
    cout << a[2] << endl;  // Should print the 3rd element. 
    b[1] = "b_string";  // Should change the 2nd element to “b_string”.
    cout << b;
    b[0] = "a_string";
    cout << b;
}  

}  // namespace

int main(int argc, char **argv) {
  TestPart1();
  TestPart2();
  /*
  Chain<int> a, b;  // Two empty Chains are created   
  cout << a.size() << " " << b.size() << endl; // yields 0 0
  Chain<int> d{7};  // A chain containing 7 should be created.
  cout << d;  // Should just print [7]
  Chain<int> c{d};  // Calls copy constructor for c.
  cout << c; //print [7]
  Chain<int> e = move(c);  // Move constructor for d.
  cout << e;
  a = move(e);  // Move assignment operator for a.
  cout << a;
  a.ReadChain(); // User enters a chain, for example [4: 10 30 -1 2]
  cout << a;  // Output should be what user entered.
  */
  return 0;
}
