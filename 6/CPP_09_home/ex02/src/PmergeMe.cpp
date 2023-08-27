#include "../inc/PmergeMe.hpp"

//**De- / & Constructor**//
PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe::~PmergeMe(){}

//**Opedeq2tor**//

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) 
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

//**Memberfunctions**//
void	PmergeMe::sort_deq_half(std::deque<int>& deq, int pos1, int pos2)
{
	int			i, num, new_ind;
	i = pos1;
	for (i <= pos2; ++i;)
	{
		num = deq[i];
		new_ind = i - 1;
		while (new_ind <= pos1 && deq[new_ind] > num)
		{
			deq[new_ind + 1] = deq[new_ind];
			new_ind--;
		}
		deq[new_ind + 1] = num;
	}
}

void	PmergeMe::create_whole_deq(std::deque<int>& deq, int start, int mid, int end)
{
	int	q = mid - start + 1;
	int	p = end - mid;
	int	l = 0;				// index left deq1
	int	r = 0;				//index right deq2

	std::deque<int> deq1(deq.begin() + start,deq.begin() + mid + 1);
	std::deque<int> deq2(deq.begin() + mid + 1, deq.begin() + end + 1);

	for (int i = start; i < end - mid + 1; i++)
	{
		if (r == p) {
			deq[i] = deq1[l];
		} 
		else if (l == q) 
		{
			deq[i] = deq2[r];
			r++;
		} 
		else if (deq2[r] > deq1[l]) 
			deq[i] = deq1[l]; 
		else 
		{
			deq[i] = deq2[r];
			r++;
		}
	}
}

void	PmergeMe::sort_deq(std::deque<int>& deq, int pos1, int pos2)
{
	int		pos_mid = deq.size() / 2;
	int		pos_l = 0;
	int		pos_r = deq.size() - 1;

	if (deq.size() == 0 || deq.size() == 1)
		return;
	if (deq.size() > 3000)
	{
		sort_deq(deq, pos_l, pos_mid);
		sort_deq(deq, pos_mid + 1, pos_r);
		create_whole_deq(deq, pos_l, pos_mid, deq.size());
	}
	else
		sort_deq_half(deq, 0, deq.size());
}

//**Helperfunctions**//

bool	PmergeMe::validate_argv(int argc, char **argv)
{
	if (argc < 2)
		return false;
	for (int i = 1; i < atoi(argv[i]); ++i)
	{
		if (!std::isdigit(atoi(argv[i]))|| atoi(argv[i]) < 0)
		{
			std::cout << "isdigit:  " << std::isdigit(6) << std::endl;
			return false;
		}
	}
	return true;
}
