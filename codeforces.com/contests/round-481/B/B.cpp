#include <bits/stdc++.h>

using namespace std;

int resolve(string & s, int n){
	int c = 0;
	int r = 0;
	for (int i = 0; i < n; i += 1){
		if (s[i] == 'x') c += 1;
		if (s[i] != 'x' || i + 1 >= n){
			if (c >= 3) r += c-2;
			c = 0;
		}
	}
	return r;
}

int main(){
	int n;
	string s;

	//parsing
	cin >> n;
	cin >> s;
	//find solution
	cout << resolve(s,n) << "\n";
}
