// Connie Deng
// Main file for Part2(a) of Homework 2.

#include "avl_tree.h"
#include "sequence_map.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

namespace
{

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree)
{
  // Code for running Part2(a)
  // You can use public functions of TreeType. For example:
  //a_tree.insert(10);

  //error file checking
  ifstream inStream(db_filename);
  if (inStream.fail())
  {
    cerr << "Filename not found." << std::endl;
    exit(1);
  }

  //populate tree
  string db_line, garbage_line;
  string an_enz_acro;

  for (int i = 0; i < 10; i++){ getline(inStream, garbage_line); } //begin reading on line 11
  vector<string> enzymeID;
    
    while (std::getline(inStream, db_line, '/'))
    {
      if (db_line.empty()){
        an_enz_acro = enzymeID[0];
        enzymeID.erase( enzymeID.begin() ); //delete enzyme_acronym
        
        if(enzymeID.size() == 0)
          continue;

        else{
          for(int i = 0; i < enzymeID.size(); i++){
            SequenceMap new_sequence_map(enzymeID[i], an_enz_acro);
            a_tree.insert(new_sequence_map);
          }
        }
        enzymeID.clear();
        continue;
      }
    
      else
        enzymeID.push_back(db_line);
    }

  inStream.close();
  //cout << endl << "Printing Tree:" << endl;
  //a_tree.printTree();

} //end QueryTree
} // namespace

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  cout << "Input filename is " << db_filename << endl;
  //Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  //AvlTree<int> b_tree;
  AvlTree<SequenceMap> a_tree;
  QueryTree(db_filename, a_tree);

  vector<string> userInputs;
  string input1, input2, input3;
  cout << "enter THREE recognition sequences): ";
  cin >> input1 >> input2 >> input3;
  cout << endl;
  //vector of inputs
  userInputs.push_back(input1); userInputs.push_back(input2); userInputs.push_back(input3);
  
  for (int i = 0; i < 3; i++){
      string i_enz_acro;
      SequenceMap input_sequence_map(userInputs[i]);
      
      if(a_tree.contains(input_sequence_map)){ 
          cout << a_tree.find(userInputs[i]) << " ";
          //cout << endl; 
      }
      
      else{ cout << "Not Found" << endl; }
      }
  return 0;
}
