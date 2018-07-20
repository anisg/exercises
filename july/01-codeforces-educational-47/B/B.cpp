#include <bits/stdc++.h>

using namespace std;

void printPartial(char a, int an, char b, int bn){
	for (int i = 0; i < an; i += 1)
		cout << a;
	for (int i = 0; i < bn; i += 1)
		cout << b;
}

void printSolution(string & s){
	char m = -1;
	int c[3] = {0,0,0};
	for (int i = 0; i < s.size(); i += 1){
		if (s[i] == '1'){
			c[1] += 1;
		}
		else if (s[i] == '0'){
			if (m == '2'){
				printPartial('1', c[1], '2', c[2]);
				c[0] = 0; c[1] = 0; c[2] = 0;
			}
			m = '0';
			c[0] += 1;
		}
		else if (s[i] == '2'){
			if (m == '0'){
				printPartial('0', c[0], '1', c[1]);
				c[0] = 0; c[1] = 0; c[2] = 0;
			}
			m = '2';
			c[2] += 1;
		}
	}
	printPartial('x', 0, '0', c[0]);
	printPartial('x', 0, '1', c[1]);
	printPartial('x', 0, '2', c[2]);
	cout << "\n";
}

int main(){
	string s;

	//parsing
	cin >> s;
	//find solution
	printSolution(s);
}
