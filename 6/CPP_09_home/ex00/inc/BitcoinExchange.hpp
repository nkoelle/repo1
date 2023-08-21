#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <exception>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class BitcoinExchange
{
    private :
            std::map<std::string, float> _ExchangeRate;
            
    public :
            //**Con- & Destructor**//
            BitcoinExchange();
            BitcoinExchange(const BitcoinExchange& obj);
            ~BitcoinExchange();

            //**Operator**//
            BitcoinExchange&    operator=(const BitcoinExchange& obj);

            //**Getter**//
            std::map<std::string, float> &          get_er();

            //**Setter**//
            void                                    set_map(std::string key, float value);

            //**member functions**//
            void                                    load_csv_to_map();
            void                                    comp_map_input(std::string input);
            std::map<std::string, float>::iterator  find_closest_date(std::string date);


            //**helper functions**//
            bool                                    check_valid_date(std::string s);
            float                                   str_to_float(std::string& s);
            std::string                             get_filepath(std::string& s);
};