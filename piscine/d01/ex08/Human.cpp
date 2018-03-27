#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
	std::cout << "meleeAttack:" << target << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << "rangedAttack:" << target << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "intimidatingShout:" << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	std::string names[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	void (Human::*actions[])(std::string const &) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout, nullptr};

	for (int i = 0; actions[i] != nullptr; i += 1)
		if (action_name == names[i])
			(this->*actions[i])(target);
}
