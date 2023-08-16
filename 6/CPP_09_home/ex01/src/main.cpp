#include "../inc/RPN.hpp"

int	main(int argc, char *argv[])
{
	RPN	rpn;
	if (argc != 2)
	{
		std::cout << "ERROR: no input file found." << std::endl; 
		return (0);
	}
	rpn.load_input(argv[1]);
	return (0);
}
