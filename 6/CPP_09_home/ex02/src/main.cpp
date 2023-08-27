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
	t_begin = clock();
	Pgm.sort_vec(vec, 0 , vec.size());
	t_end = clock();
	diff_vec = t_end - t_begin;
	std::cout << "After: " << std::endl;
	Pgm.print_vec(vec);
	Pgm.print_vec(deq);
	//std::cout << "Time to process a range of 3000 elements with std::vector :: " << diff_vec / CLOCKS_PER_SEC * 1000000.0 << std::endl; // vector diff
	std::cout << "Time to process a range of 3000 elements with std::vector :: " << diff_vec << std::endl; // vector diff 
	std::cout << "Time to process a range of 3000 elements with std::deque :: " << diff_deq / CLOCKS_PER_SEC * 1000000.0 <<std::endl; //  deq diff
	return (0);
}
