#include <bits/stdc++.h>

using namespace std;

//parse,print
template<typename T> T & parse(T & t){cin >> t; return t;} template<typename T, typename ...Args> void parse(T & t, Args & ...args){parse(t);parse(args...);}
template<typename T> void print(T t) {cout << t << "\n";} template<typename T, typename ...Args> void print(T t, Args ...args){cout << t; print(args...);}

/* ---------------------------------------- */

int solve(vector<int> & A, int n){
	for (int i = 0; i < n; i += 1){

	}
	return 0;
}

int main(){
	int n;
	int m;
	vector<float> A;
	vector<float> B;

	//parsing
	parse(n);
	parse(m);
	A.reserve(n);
	for (int i = 0; i < n; i += 1){
		float a;
		A[i] = parse(a);
	}
	B.reserve(n);
	for (int i = 0; i < n; i += 1){
		float b;
		B[i] = parse(b);
	}
	//find solution
 	print(solve(A,n));
}
