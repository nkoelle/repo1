#include "../inc/RPN.hpp"

int	main(void)
{
	RPN	rpn;
	std::string	s =	 "(1 1 +)";
	//if (argc != 2)
	//{
	//	std::cout << "ERROR: no input file found." << std::endl; 
	//	return (0);
	//}
	rpn.load_input(s);
	//std::cout << argv[1] << std::endl;
	return (0);
}