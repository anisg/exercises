#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() : _type("Marcheur Blanc") {
	srand((int)time(0));
}

ZombieEvent::~ZombieEvent() {
}

void ZombieEvent::setZombieType(std::string type){
	this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	return new Zombie(this->_type, name);
}

void ZombieEvent::randomChump()
{
	std::string a[] = {"Rick", "Karl", "Caroll"};
	int n = 3;
	Zombie z = Zombie(this->_type, a[(rand() % n)]);
	z.annonce();
}
