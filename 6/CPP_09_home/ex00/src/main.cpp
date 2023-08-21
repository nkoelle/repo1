#include "../inc/BitcoinExchange.hpp"

int main(int argc, char *argv[]) 
{
    BitcoinExchange rpn;

    if (argc != 2) 
    {
        std::cout << "Error: please input like: [ ./btc inputfile ]" << std::endl;
        return 1;
    }
    rpn.load_csv_to_map();
    rpn.comp_map_input(argv[1]);
    return 0;
}