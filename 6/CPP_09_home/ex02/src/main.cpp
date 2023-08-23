#include "../inc/PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	std::vector<int>	vec;
	PmergeMe			Pgm;


	if (!Pgm.validate_argv(argc, argv))
		{
			std::cout << "Error: invalid input!" << std::endl;
			return (1);
		}
	for (int i = 1; i < argc; i++)
		vec.push_back(atoi(argv[i]));
	std::deque<int>		deq(vec.begin(), vec.end());
	std::cout << "Before: " << std::endl;
	Pgm.print_vec(vec);
	Pgm.print_vec(deq);
	return (0);
}
