#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";

	//pointer
	std::string *ps = &s;
	//reference
	std::string & rs = s;

	//print using pointer (by deferencing)
	std::cout << (*ps) << std::endl;

	//print using reference
	std::cout << rs << std::endl;

	return 0;
}
