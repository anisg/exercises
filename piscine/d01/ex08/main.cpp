#include "Human.hpp"

int main()
{
	Human h = Human();

	h.action("meleeAttack", "Hoheee");
	h.action("meleeAttack", "Yaaaaaaa");

	h.action("rangedAttack", "Husss");
	h.action("rangedAttack", "*concentrate*");

	h.action("intimidatingShout", "Boooouuuum");
	h.action("intimidatingShout", "Vlaaan");

	h.action("unknown", "Heyyy");

}
