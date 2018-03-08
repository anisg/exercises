#include <bits/stdc++.h>

using namespace std;

bool isLowerCase(char c){
	if (c >= 'a' && c <= 'z')
		return true;
	return false;
}
int main() {
	string s;

	getline(cin, s);

	for (size_t i = 0; i < s.length(); i+=1){
		if ((i == 0 || s[i-1] == ' ') && isLowerCase(s[i]))
			s[i] = s[i] - 'a' + 'A';
	}
	cout << s << endl;
}
