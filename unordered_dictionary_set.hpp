// Ramela Ramnauth
//  unordered_dictionary_set.hpp
//  Spell_Check
//
//  Created by Ramela Ramnauth on 11/18/18.
//  Copyright © 2018 Ramela Ramnauth. All rights reserved.
//

#ifndef unordered_dictionary_set_hpp
#define unordered_dictionary_set_hpp

#include <unordered_set>
#include <vector>

class unordered_dictionary_set
{
private:
    
    //dictionary
    std::unordered_set<std::string> myset;
    
    // contents of user file
    std::vector<std::string> user_file;
    
    //results of spell checking
    std::vector< std::vector< std::string > >  results;

    void find_in_dictionary();

    bool is_good_match(std::string in_dict, std::string bad_word);
    
    void find_correct_spellings();
    
    void swap_test();
    
public:
    unordered_dictionary_set();
    ~unordered_dictionary_set();
    
    void load_dictionary(const char* newfile);
    
    void load_user_file(const char* newfile);
    
    void print();
    
    void perform_corrections();
    
    
};
#include "unordered_dictionary_set.cpp"
#endif /* unordered_dictionary_set_hpp */
