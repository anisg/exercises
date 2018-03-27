#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Zombie.hpp"

class ZombieEvent
{
	public:
		ZombieEvent();
		~ZombieEvent();
		Zombie* newZombie(std::string name);
		void setZombieType(std::string type);
		void randomChump();

	private:
		std::string _type;
};

#endif
