#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <utility>
#include <cctype>


class PmergeMe
{
	private:
		std::vector<int>	sequence;

	public:
	//**De-/ & Constructor**//
		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		~PmergeMe();

	//**Operator**//
		PmergeMe& operator=(const PmergeMe& rhs);

	//**Memberfuncitons**//
		void	load_input(std::string input);

	//*Helperfuncitons**//
		bool	validate_argv(int argc,char **argv);
	//**Templatefunctions
		template<typename T>
		void	print_vec(T	const& vec)
		{
			typename T::const_iterator	it;
			for (it = vec.begin(); it != vec.end(); ++it)
				std::cout << *it;
			std::cout << std::endl;
		}
};