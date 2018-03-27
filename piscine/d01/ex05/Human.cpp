#include "Human.hpp"

Human::Human() {
	std::cout << "*Hell yeay! a human has been created.*" << std::endl;
}

Human::~Human() {
	std::cout << "*Hell yeah! I mean why god! :'( A human died...*" << std::endl;
}

std::string Human::identify() const
{
	return this->_brain.identify();
}

Brain const & Human::getBrain()
{
	return this->_brain;
}
