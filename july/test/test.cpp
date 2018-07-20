#include <bits/stdc++.h>

using namespace std;

//parse,print
template<typename T> T & parse(T & t){cin >> t; return t;} template<typename T, typename ...Args> void parse(T & t, Args & ...args){parse(t);parse(args...);}
template<typename T> void print(T t) {cout << t << "\n";} template<typename T, typename ...Args> void print(T t, Args ...args){cout << t; print(args...);}

/* ---------------------------------------- */
/* -------------   Solution   ------------- */

int resolve(vector<int> & A, int n){
	for (int i = 0; i < n; i++){

	}
	return 0;
}

int main(){
	int n, k;
	vector<int> A;

	//parsing
	parse(n, k);
	A.reserve(n);
	for (int i = 0; i < n; i++){
		int a;
		A[i] = parse(a);
	}
	//solution
 	print(resolve(A,n));
}
