#include "./inc/RPN.HPP"

//**De- / & Constructor**//
RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& obj){}

//**Operator**//
RPN& RPN::operator=(const RPN& obj)
{}

//**Memberfuncitons**//
void	RPN::load_input(std::string	input)
{
	std::istringstream	in(input);
	std::string			raw_str;

	if(!in.good())
		std::cout << "ERROR: could not open input file";
	in >> raw_str;
	if (raw_str.length() > 17)
		std::cout << "ERROR: too many arguments";
	

}

//*Helperfuncitons**//