#include <iostream>
#include "Pony.hpp"

void ponyOnTheHeap()
{
	Pony *pony = new Pony((char *)"Bouton");

	pony->hi();

	delete pony;
}

void ponyOnTheStack()
{
	Pony pony = Pony((char *)"Bourrasque");

	pony.hi();
}


int main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return 0;
}
