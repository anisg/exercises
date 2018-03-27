#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int N);
		~ZombieHorde();
		void annonce();

	private:
		Zombie *_horde;
		int _N;
};

#endif
