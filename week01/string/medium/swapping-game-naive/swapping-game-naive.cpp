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

void unswap(string & s)
{
	size_t n = s.length();
	string cpy(s.length(), '\0');
	int a = 0;
	for (size_t i = 0; i < n; i+=2) {
		if (i+1 < n)
			cpy[n-1-a] = s[i+1];
		cpy[a] = s[i];
		a += 1;
	}
	s = cpy;
}

string performUnswap(string & s, int nb){
	for (int i = 0; i < nb;i++){
		cout << s << endl;
		unswap(s);
	}
	return s;
}

int main() {
	int nb;
	string s;

	cin >> nb;
	cin >> s;
	cout << performUnswap(s, nb) << endl;
}
