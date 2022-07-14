#include <bits/stdc++.h>

using namespace std;

//parse,print
template<typename T> T & parse(T & t){cin >> t; return t;} template<typename T, typename ...Args> void parse(T & t, Args & ...args){parse(t);parse(args...);}
template<typename T> void print(T t) {cout << t << "\n";} template<typename T, typename ...Args> void print(T t, Args ...args){cout << t; print(args...);}

/* ---------------------------------------- */

int solve(string & a, string & b){
	int x;

	x = 0;
	while (x < b.size() && a[x] == b[x])
		x += 1;
	if (x == b.size())
		return 0;
	int i,j;
	i = a.size()-1;
	j = b.size()-1;
	while (i >= x && j >= x && a[i] == b[j]){
		i -= 1;
		j -= 1;
	}
	if (j < x)
		return 0;
	return j-x+1;
}

int main(){
	string a,b;

	parse(a);
	parse(b);
 	print(solve(a,b));
}
