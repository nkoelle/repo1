#pragma once RPP_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>


class RPN
{
	private:

	public:

	//**De- / & Constructor**//
	RPN();
	RPN(const RPN& obj);
	~RPN();

	//**Operator**//
	RPN& operator=(const RPN& obj);

	//**Memberfuncitons**//
	void	load_input(std::string	input);

	//*Helperfuncitons**//

};