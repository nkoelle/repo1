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

//**Memberfuncitons**//
void	PmergeMe::load_input(std::string input)
{

}
