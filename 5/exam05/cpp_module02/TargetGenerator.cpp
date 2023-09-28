#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){}

TargetGenerator::TargetGenerator(const TargetGenerator& copy)
{
    *this = copy;
}

TargetGenerator&    TargetGenerator::operator=(const TargetGenerator& origin)
{
    if (this != &origin)
        *this = origin;
    return (*this);
}

void    TargetGenerator::learnTargetType(ATarget* type)
{
    if (type)
        targ_[type->getType()] = type;
}

void    TargetGenerator::forgetTargetType(std::string const& target)
{
	if (targ_.find(target) != targ_.end())
		targ_.erase(targ_.find(target));
}

 ATarget*    TargetGenerator::createTarget(std::string const & new_targ)
 {
    ATarget* tmp = NULL;

	if (targ_.find(new_targ) != targ_.end())
		tmp = targ_[new_targ];
	return (tmp);
 }