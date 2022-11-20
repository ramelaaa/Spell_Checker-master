// Ramela Ramnauth
//  dictionary_set.cpp
//  Spell_Check
//
//  Created by Ramela Ramnauth on 11/18/18.
//  Copyright © 2018 Ramela Ramnauth. All rights reserved.
//

#ifndef dictionary_set_cpp
#define dictionary_set_cpp

#include "dictionary_set.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

dictionary_set::dictionary_set() {};

dictionary_set::~dictionary_set() {};

void dictionary_set::load_user_file(const char* newfile)
{
    std::ifstream wordfile(newfile);
    std::string line,temp;
    while(!wordfile.eof())
    {
        wordfile >> line;
        std::remove_copy_if(line.begin(), line.end(),
                            std::back_inserter(temp), //Store output
                            std::ptr_fun<int, int>(&std::ispunct)
                            );
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        user_file.push_back(temp);
        temp.clear();
    }
    wordfile.close();
    //std::cout << "the size of user file is " << user_file.size() << std::endl;
}

void dictionary_set::load_dictionary(const char* newfile)
{
    std::ifstream wordfile(newfile);
    std::string line;
    
    while(!wordfile.eof())
    {
        //std::getline (std::cin,line);
        wordfile >> line;
        line.erase(line.find_last_not_of(" \n\r\t")+1);
        myset.insert(line);
    }
    
    wordfile.close();
    //std::cout << "the size of myset is " << myset.size() << std::endl;
}

void dictionary_set::find_in_dictionary()
{
    std::set<std::string>::const_iterator got;
    
    
    for(int i = 0; i<user_file.size(); i++)
    {
        //std::cout <<i << " " << user_file[i] << std::endl;
        got = myset.find(user_file[i]);
        if ( got == myset.end() )
        {
            
            std::vector<std::string> temp;
            
            temp.push_back(user_file[i]);
            
            results.push_back(temp);
            
            
        }
    }
    //std::cout << "The size of results is " << results.size() << std::endl;
}

bool dictionary_set::is_good_match(std::string in_dict, std::string bad_word)
{
    int bookmark = 0;
    std::string my_dict_sub_str, my_bad_word_sub_str;
    
    for(int i = 0; i<std::min(in_dict.size(),bad_word.size());i++)
    {
        if(in_dict[i] !=  bad_word[i])
        {
            bookmark = i;
            break;
        }
    }
    
    if(in_dict.size() == bad_word.size())
    {
        my_dict_sub_str = in_dict.substr(bookmark+1, in_dict.size()-1);
        my_bad_word_sub_str = bad_word.substr(bookmark+1, bad_word.size()-1);
        
    }
    else if(in_dict.size() < bad_word.size())
    {
        my_dict_sub_str = in_dict.substr(bookmark,in_dict.size()-1);
        my_bad_word_sub_str = bad_word.substr(bookmark+1, bad_word.size()-1);
    }
    else if(in_dict.size() > bad_word.size())
    {
        my_dict_sub_str = in_dict.substr(bookmark+1,in_dict.size()-1);
        my_bad_word_sub_str = bad_word.substr(bookmark, bad_word.size()-1);
    }
    
    if(my_dict_sub_str == my_bad_word_sub_str)
    {
        return true;
    }
    
    return false;
}

void dictionary_set::find_correct_spellings()
{
    std::set<std::string>::const_iterator got;
    for(int i = 0; i<results.size(); i++)
    {
        for (got = myset.begin(); got != myset.end(); ++got)
        {
            if( is_good_match(*got, results[i][0]))
            {
                results[i].push_back(*got);
            }
        }
    }
}

void dictionary_set::swap_test()
{
    for(int j = 0; j < results.size(); j++)
    {
        for(int i = 0; i<results[j][0].size()-1; i++)
        {
            std::set<std::string>::const_iterator got;
            std::string temp = results[j][0];
            std::swap(temp[i],temp[i+1]);
            got = myset.find(temp);
            if ( got != myset.end() )
            {
                results[j].push_back(temp);
            }
            
        }
    }
}

void dictionary_set::print()
{
    for(int i = 0; i<results.size(); i++)
    {
        for(int j = 0; j<results[i].size(); j++)
        {
            if(j == 0)
            {
                std::cout << "Suggestions for " << results[i][j] << ": \n";
            }
            else
            {
                std::cout << j <<". " << results[i][j]<<" \n";
            }
        }
    }
}

void dictionary_set::perform_corrections()
{
    find_in_dictionary();
    find_correct_spellings();
    swap_test();
}

#endif

