#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {
}

void Zombie::setTypeAndName(std::string type, std::string name)  {
	this->_type = type;
	this->_name = name;
	std::cout << "*Hoo zombie " << this->_name << " emerge from the ground*" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "*Cool! zombie " << this->_name << " dies*" << std::endl;
}

void Zombie::annonce(){
	std::cout << "<" << this->_name << " (" << this->_type << ")> " << "Braiiiins..." << std::endl;
}
