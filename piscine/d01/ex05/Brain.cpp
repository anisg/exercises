#include "Brain.hpp"

Brain::Brain() {
	std::cout << "*Waw it\'s beautiful! a brain has been created.*" << std::endl;
}
Brain::~Brain() {
	std::cout << "*Sadly a brain has leave us today...*" << std::endl;
}

std::string Brain::identify() const
{
	std::stringstream out;
	out << "0x" << std::hex << (size_t)this;
	return out.str();
}
