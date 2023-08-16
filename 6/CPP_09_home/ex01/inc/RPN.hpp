#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>


class RPN
{
	private:
	std::stack<int>	stack;

	public:
	//**De-/ & Constructor**//
	RPN();
	RPN(const RPN& obj);
	~RPN();

	//**Operator**//
	RPN& operator=(const RPN& obj);

	//**Memberfuncitons**//
	void	load_input(std::string	input);

	//*Helperfuncitons**//

};