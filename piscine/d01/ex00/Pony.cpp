#include <iostream>
#include "Pony.hpp"

Pony::Pony(char *name) : _name(name) {
	std::cout << "a new pony is born: " << this->_name << std::endl;
}

Pony::~Pony() {
	std::cout << "What a sadness! " << this->_name << " dies :(" << std::endl;
}

void Pony::hi(){
	std::cout << "*Hiiiiii*, hi my name is " << this->_name << ", how are you?" << std::endl;
}
