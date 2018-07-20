#include <bits/stdc++.h>

using namespace std;

//parse,print
template<typename T> T & parse(T & t){cin >> t; return t;} template<typename T, typename ...Args> void parse(T & t, Args & ...args){parse(t);parse(args...);}
template<typename T> void print(T t) {cout << t;} template<typename T, typename ...Args> void print(T t, Args ...args){print(t);print(args...);}

/* ---------------------------------------- */
/* -------------   Solution   ------------- */

long long resolve(long long n){
	if (n < 4) return 0;
	long long x = log2(n) - 1;
	return x * (x + long((n-pow(2,x+1))/x));
}

int main(){
	int t;

	//parsing
	parse(t);
	for (int _ = 0; _ < t; _ += 1){
		long long n;
		parse(n);
		//find solution
		print(resolve(n), "\n");
	}
}
