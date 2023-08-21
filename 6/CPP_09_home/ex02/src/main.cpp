#include "../inc/PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	std::vector<int>	vec;
	std::deque<int>		deq;


	if (argc < 2)
	{
		std::cout << "ERROR: no input found." << std::endl; 
		return (0);
	}
	for (int i = 1; argc > i ; i++)
	{
		//check number
		vec.push_front(argv[i]);
		deq.push_front(argv[i]);
	}
	return (0);
}
