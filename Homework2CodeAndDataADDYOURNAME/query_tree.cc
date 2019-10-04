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

  for (int i = 0; i < 10; i++){ getline(inStream, garbage_line); } //begin reading on line 11.
  
  /*while(getline(inStream, db_line))
  {
    string an_enz_acro = db_line.substr(0, db_line.find('/')); // Find substring of sentence with '/' first seen
    db_line.erase(0, db_line.find('/')+1); // Then delete that part in sentence

    // Removing the last '/'; Sentence ends with "//"
    while (db_line != "/")
    { 
      string a_reco_seq = db_line.substr(0,db_line.find('/')); // Find sequence
      db_line.erase(0,db_line.find('/')+1); // Delete than from sentence
      SequenceMap new_sequence_map{a_reco_seq,an_enz_acro}; // Construct SequenceMap with acro and sequence
      a_tree.insert(new_sequence_map); // Insert into a_tree
    }
  }*/

  vector<string> enzymeID;
    
    while (std::getline(inStream, db_line, '/'))
    {
      if (db_line.empty()){
        if(enzymeID[0] == NULL) { break; }
        an_enz_acro = enzymeID[0]; //works
        //cout << an_enz_acro << " ";
        enzymeID.erase( enzymeID.begin() ); //delete enzyme_acronym
        
        for(int i = 0; i < enzymeID.size(); i++){
          //cout << i << " ";
          //cout << enzymeID[i] << " " << endl; //works
          SequenceMap new_sequence_map(enzymeID[i], an_enz_acro);
          a_tree.insert(new_sequence_map);
        }
        //cout << endl;
        enzymeID.clear();
        //cout << "cleared";
        continue;
      }
    
      else
        //std::cout << db_line; //reads correctly
        enzymeID.push_back(db_line);
    }
  inStream.close();
  a_tree.printTree();
}
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
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  //AvlTree<int> a_tree;
  AvlTree<SequenceMap> a_tree;
  QueryTree(db_filename, a_tree);

  string input1, input2, input3;
  //cout << "enter THREE recognition sequences): ";
  //cin >> input1 >> input2 >> input3;
  //a_tree.printTree();
  //cout << input1 + " " + input2 + " " + input3;
  return 0;
}
