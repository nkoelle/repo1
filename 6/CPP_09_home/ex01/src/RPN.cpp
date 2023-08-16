#include "../inc/RPN.hpp"

//**De- / & Constructor**//
RPN::RPN(){}

RPN::~RPN(){}

//**Operator**//

RPN::RPN(const RPN& obj)
{
	*this = obj;
}
RPN& RPN::operator=(const RPN& obj) 
{
	if (this != &obj)
		*this = obj;
	return *this;
}

//**Memberfuncitons**//
void	RPN::load_input(std::string	input)
{
	std::istringstream	in(input);
	std::string			raw_str;
	int					ele1;
	int					ele2;

	if(!in.good()) {
		std::cout << "ERROR: could not open input file";
		return;
	}
	while (in >> raw_str)
	{
		if (isdigit(raw_str.front())) // store numbers
			stack.push(atoi(raw_str.c_str()));
		else
		{
			if (stack.size() < 2)
			{
				std::cout << "Error" << std::endl;
				return ;
			}
			ele2 = stack.top();
			stack.pop();
			ele1 = stack.top();
			stack.pop();
			if (raw_str.front() == '+')
				stack.push(ele1 + ele2);
			else if (raw_str.front() == '-')
				stack.push(ele1 - ele2);
			else if (raw_str.front() == '/')
				stack.push(ele1 / ele2);
			else if (raw_str.front() == '*')
				stack.push(ele1 * ele2);
			else
				std::cout << "error" << std::endl;
		}
	}
	std::cout << stack.top() << std::endl;
}
