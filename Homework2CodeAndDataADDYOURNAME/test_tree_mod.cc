// Connie Deng
// Main file for Part2(c) of Homework 2.

#include "avl_tree_modified.h"
#include "sequence_map.h"
#include "avl_tree.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

namespace {

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
  // Code for running Part2(b)  

ifstream inStream(db_filename);
  //2b-1
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

    //a_tree.printTree();

    cout << "2: " << a_tree.numOfNodes() << endl; // Prints the number of nodes in your tree N
    cout << "3a: " << a_tree.averageDepth() <<endl; // Prints the average depth
    cout << "3b: " << a_tree.averageDepth()/log2(a_tree.numOfNodes()) <<endl; // Prints the ratio of the average depth to log2
    
    ifstream query_Stream{"sequences.txt"}; // Query stream
    string sentence;
    int successful_Queries = 0; // Successful queries
    int num_Of_Queries = 0;       // Total number of queries made
    int num_Of_Recursive_Queries = 0;

    while (query_Stream >> sentence)
    { 
      num_Of_Queries++;
      num_Of_Recursive_Queries += a_tree.totalRecursion(sentence);
      if (a_tree.contains(sentence))
      {
        successful_Queries++;
      }
    }
    query_Stream.close();      
    
    cout << "4a: " << successful_Queries <<endl; // Prints the total number of successful queries (number of strings found)
    cout << "4b: " << double(num_Of_Recursive_Queries)/num_Of_Queries <<endl; // Prints the average number of recursion calls
    
    ifstream remove_Stream{"sequences.txt"}; // Remove Stream
    int total_Num_Of_Node = a_tree.numOfNodes(); // Total number of nodes originally 
    int num_Of_Remove = 0; // Number of remove called
    int num_Of_Recursive_Remove = 0; // Number of recursive remove called

    while (remove_Stream >> sentence)
    {
      num_Of_Remove++;
      num_Of_Recursive_Remove += a_tree.totalRecursion(sentence);
      a_tree.remove(sentence);
      remove_Stream >> sentence;  // This is how we skip every other sequence.
    }
    remove_Stream.close();

    int num_Of_Node_After_Remove = a_tree.numOfNodes(); // Number of Node after remove
    int successful_Remove = total_Num_Of_Node - num_Of_Node_After_Remove; // Number of remove made
    cout << "5a: " << successful_Remove <<endl; // Prints the total number successful removes
    cout << "5b: " << double(num_Of_Recursive_Remove)/num_Of_Remove <<endl; // Prints the average number of recursion calls
    
    cout << "6a: " << a_tree.numOfNodes() <<endl; // Prints number of nodes in your tree
    cout << "6b: " << a_tree.averageDepth() <<endl; // Prints the average depth
    cout << "6c: " << a_tree.averageDepth()/log2(a_tree.numOfNodes()) <<endl; // Prints the ratio of the average depth to log2N
  }
} // namespace

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  //AvlTree<int> a_tree;
  cout<<endl;
  AvlTree<SequenceMap> a_tree;
  TestTree(db_filename, seq_filename, a_tree);

  return 0;
}
