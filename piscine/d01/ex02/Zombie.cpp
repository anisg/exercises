#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name) : _type(type), _name(name) {
	std::cout << "*a new zombie awaken: " << this->_name << "*" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "*Cool! " << this->_name << " dies*" << std::endl;
}

void Zombie::annonce(){
	std::cout << "<" << this->_name << " (" << this->_type << ")> " << "Braiiiins..." << std::endl;
}
