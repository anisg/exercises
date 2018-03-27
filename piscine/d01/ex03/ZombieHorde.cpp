#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) {
	srand((int)time(0));
	std::string a[] = {"Bobo", "Jon", "Barbare", "Magma", "Acid", "Ugly"};
	int n = 6;
	this->_horde = new Zombie[N];
	for (int i = 0; i < N; i += 1){
		this->_horde[i].setTypeAndName("Ugly Zombie", a[(rand() % n)]);
	}
	this->_N = N;
	std::cout << "The horde has been created" << std::endl;
}

ZombieHorde::~ZombieHorde() {
	delete [] this->_horde;
	std::cout << "The horde miserably dies!" << std::endl;
}


void ZombieHorde::annonce()
{
	for (int i = 0; i < this->_N; i += 1)
	{
		this->_horde[i].annonce();
	}
}
