#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	public:
		Zombie(std::string type, std::string name);
		~Zombie();
		void annonce();

	private:
		std::string _type;
		std::string _name;
};

#endif
