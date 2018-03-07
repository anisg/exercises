/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <iostream>
#include <string>

using namespace std;

string unswap(string & s)
{
	
}

string performUnswap(string & s, int nb){
	for (int i = 0; i < nb;i++){
		unswap(s);
	}
	return s;
}
int main() {
	int nb;
	string s;

	cin >> nb;
	cin >> s;
	cout << performUnswap(s, nb) << end;
}
