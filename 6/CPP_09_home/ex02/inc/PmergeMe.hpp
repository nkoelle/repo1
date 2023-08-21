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

};