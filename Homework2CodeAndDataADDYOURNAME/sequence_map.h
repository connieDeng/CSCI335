// Connie Deng
// Part 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SequenceMap
{
/*---------------public members--------------------*/
public:

    // The Big Five:
    ~SequenceMap() = default; //destructor
    SequenceMap(const SequenceMap & rhs) = default; //1 arg constructor
    SequenceMap(SequenceMap && rhs) = default; //copy constructor
    SequenceMap& operator= (const SequenceMap & rhs) = default; //copy assignment
    SequenceMap& operator= (SequenceMap && rhs) = default; //move constructor
    //constructor given 2 strings parameters
    SequenceMap(const std::string &a_rec_seq, const std::string &an_enz_acro){
        recognition_sequence_ = a_rec_seq;
        
        //vector that contain an_enz_acro
        enzyme_acronyms_ = {an_enz_acro}; 
    }

    //returns true if lhs < rhs
    //returns false if lhs >= rhs
    bool operator<(const SequenceMap &rhs) const{
        return recognition_sequence_ < rhs.recognition_sequence_;
    }

    //printing sequence map
    friend std::ostream& operator<<(std::ostream& os, const SequenceMap& s_map){
        os << s_map.recognition_sequence_ << ": ";
        for(int i = 0; i < s_map.enzyme_acronyms_.size(); i++){
            os << s_map.enzyme_acronyms_[i] << " ";
        }
        os << std::endl;
        return os;
    }

    //merge 2 sequence maps
    void Merge(const SequenceMap &other_sequence){
        for(int i = 0; i < other_sequence.enzyme_acronyms_.size(); i++){
            enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
        }
    }
/*---------------private members--------------------*/
private:
    string recognition_sequence_;
    vector<string> enzyme_acronyms_;

}; //end of class