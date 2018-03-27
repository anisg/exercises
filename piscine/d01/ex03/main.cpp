#include <iostream>
#include "ZombieHorde.hpp"
#include "Zombie.hpp"

int main(void)
{
	std::cout << "creating a little horde of 4 zombies:" << std::endl;
	ZombieHorde *h1 = new ZombieHorde(4);
	h1->annonce();
	delete h1;

	std::cout << "now 10 zombies:" << std::endl;
	ZombieHorde h2 = ZombieHorde(10);
	h2.annonce();
	return 0;
}
