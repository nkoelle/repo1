#include "../inc/PmergeMe.hpp"

//**De- / & Constructor**//
PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe::~PmergeMe(){}

//**Operator**//

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) 
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

//**Memberfunctions**//


//**Helperfunctions**//

bool	PmergeMe::validate_argv(int argc, char **argv)
{
	if (argc < 2)
		return false;
	for (int i = 1; i < atoi(argv[i]); ++i)
	{
		if (!isdigit(atoi(argv[i]))|| atoi(argv[i]) < 0)
		{
			std::cout << "isdigit:  " << isdigit(6) << std::endl;
			return false;
		}
	}
	return true;
}

