#include "../inc/PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	std::vector<int>	vec;
	PmergeMe			Pgm;
	clock_t				t_begin, t_end, diff_vec, diff_deq;

	// if (!Pgm.validate_argv(argc, argv))
	// {
	// 	std::cout << "Error: invalid input!" << std::endl;
	// 	return (1)
	for (int i = 1; i != argc ; ++i)
		vec.push_back(atoi(argv[i]));
	std::deque<int>		deq(vec.begin(), vec.end());
	std::cout << "Before: " << std::endl;
	Pgm.print_vec(vec);
	t_begin = clock();
	Pgm.sort_deq(deq, 0 , deq.size());
	t_end = clock();
	diff_deq = t_end - t_begin;
	std::cout << "After: " << std::endl;
	std::cout << "Time to process a range of 3000 elements with std::vector :: " << std::endl;
	std::cout << "Time to process a range of 3000 elements with std::deque :: " << std::endl;
	return (0);
}