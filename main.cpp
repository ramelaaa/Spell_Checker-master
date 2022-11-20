// Ramela Ramnauth
//  main.cpp
//  Spell_Check
//
//  Created by Ramela Ramnauth on 11/18/18.
//  Copyright © 2018 Ramela Ramnauth. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "unordered_dictionary_set.hpp"
#include "dictionary_set.hpp"

int main(int argc, const char * argv[]) {
    
    //check number of arguments
    if(argc != 3)
    {
        std::cerr << "Incorrect number of arguments." << std::endl;
        std::cerr << "Usage: ./[executable] [your_file.txt] [dictionary.txt]" << std::endl;
        return (-1);
    }
    
    unordered_dictionary_set dictionary1;
    dictionary_set dictionary2;
    
    std::cout << "Using unordered Set" << std::endl;
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    dictionary1.load_user_file(argv[1]);
    dictionary1.load_dictionary(argv[2]);
    dictionary1.perform_corrections();
    auto t2 = std::chrono::steady_clock::now();
    dictionary1.print();
   
    
    std::cout << "Time passed for unordered set : " <<std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count() << std::endl;
    
    std::cout << "Using Set" << std::endl;
    t1 = std::chrono::steady_clock::now();
    dictionary2.load_user_file(argv[1]);
    dictionary2.load_dictionary(argv[2]);
    dictionary2.perform_corrections();
    t2 = std::chrono::steady_clock::now();
    dictionary2.print();
   
    std::cout << "Time passed for set : " <<std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count() << std::endl;
    
    
    return 0;
}
