
#include "../inc/RPN.hpp"

int main(void)
{
	std::string test;
	
	std::istringstream	in("1 2 3 4 5");
	while(in >> test)
		std::cout << test << std::endl;
}