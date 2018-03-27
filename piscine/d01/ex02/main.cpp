#include <iostream>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main(void)
{
	//GoT
	std::cout << "Winter is coming:" << std::endl;
	ZombieEvent ze = ZombieEvent();
	Zombie *z1 = ze.newZombie("Roi");
	Zombie *z2 = ze.newZombie("Sbire");
	z1->annonce();
	z2->annonce();
	delete z1;
	delete z2;

	//Walking Dead
	std::cout << "Previously on the Walking Dead..." << std::endl;
	ze.setZombieType("Lurkers");
	Zombie *z3 = ze.newZombie("Old Chap");
	std::cout << "> a zombie just run on Rick's team, it bitted one. But who?..." << std::endl;
	ze.randomChump();
	delete z3;
	return 0;
}
