#include <bits/stdc++.h>

using namespace std;

//parse,print
template<typename T> T & parse(T & t){cin >> t; return t;} template<typename T, typename ...Args> void parse(T & t, Args & ...args){parse(t);parse(args...);}
template<typename T> void print(T t) {cout << t << "\n";} template<typename T, typename ...Args> void print(T t, Args ...args){cout << t; print(args...);}

/* ---------------------------------------- */

typedef unsigned long long ll;

ll solve(int n, int a, int b){
	ll m = INT_MAX;
	if (a > b)
		swap(a,b);
	ll ap = ceil(double(n)/2);
	ll bp = floor(double(n)/2);
	int x = 0;
	while (x < n/2){
		m = min(m, a*ap*ap + b*bp*bp);
		ap += 1;
		bp -= 1;
		x++;
	}
	return m;
}

int main(){
	int t;

	//parsing
	parse(t);
	for (int _ = 0; _ < t; _ += 1){
		int n,a,b;
		parse(n,a,b);
		print(solve(n,a,b));

	}
}
