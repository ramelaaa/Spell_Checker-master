// Ramela Ramnauth
//  dictionary_set.hpp
//  Spell_Check
//
//  Created by Ramela Ramnauth on 11/18/18.
//  Copyright © 2018 Ramela Ramnauth. All rights reserved.
//

#ifndef dictionary_set_hpp
#define dictionary_set_hpp

#include <set>
#include <vector>
#include <string>

class dictionary_set
{
private:
    
    //dictionary
    std::set<std::string> myset;
    
    // contents of user file
    std::vector<std::string> user_file;
    
    //results of spell checking
    std::vector< std::vector< std::string > >  results;
    
    void find_in_dictionary();
    
    bool is_good_match(std::string in_dict, std::string bad_word);
    
    void find_correct_spellings();
    
    void swap_test();
    
public:
    dictionary_set();
    ~dictionary_set();
    
    void load_dictionary(const char* newfile);
    
    void load_user_file(const char* newfile);
    
    void print();
    
    void perform_corrections();
    
    
};
#include "dictionary_set.cpp"

#endif /* dictionary_set_hpp */
