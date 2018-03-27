#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void setTypeAndName(std::string type, std::string name);
		void annonce();

	private:
		std::string _type;
		std::string _name;
};

#endif
