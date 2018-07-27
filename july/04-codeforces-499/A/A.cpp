#include <bits/stdc++.h>

using namespace std;

//parse,print
template<typename T> T & parse(T & t){cin >> t; return t;} template<typename T, typename ...Args> void parse(T & t, Args & ...args){parse(t);parse(args...);}
template<typename T> void print(T t) {cout << t << "\n";} template<typename T, typename ...Args> void print(T t, Args ...args){cout << t; print(args...);}

/* ---------------------------------------- */

int solve(string & s, int n, int k){
	bool *d = new bool[26]();

	for (int i = 0; i < n; i += 1){
		d[s[i]-'a'] = true;
	}
	int r = 0;
	int sel = 0;
	int i = 0;
	while (i < 26 && sel < k){
		if (d[i]){
			r += i+1;
			i += 2;
			sel += 1;
		}
		else
			i += 1;
	}
	if (sel == k)
		return r;
	return -1;
}

int main(){
	int n, k;
	string s;

	//parsing
	parse(n, k);
	parse(s);
	//find solution
 	print(solve(s,n,k));
}
