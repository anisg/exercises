#include <bits/stdc++.h>

using namespace std;

int resolve(string & s, string & t){
	int i = s.size()-1;
	int j = t.size()-1;
	while (i >= 0 && j >= 0 && s[i] == t[j]){
		i -= 1; j -= 1;
	}
	return (i + 1) + (j + 1);
}

int main(){
	string s,t;

	//parsing
	cin >> s;
	cin >> t;
	//find solution
	cout << resolve(s,t) << "\n";
}
