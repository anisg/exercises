#include <bits/stdc++.h>

using namespace std;

int middleCase(int a, int b){
	if (a == b) return 0;
	return 1;
}

int mirrorCase(int a, int b, int c, int d){
	if (a == b && c == d ||
		a == c && b == d ||
		a == d && b == c)
		return 0;
	if (a == c || a == d || b == c || b == d || c == d)
		return 1;
	return 2;
}

int resolve(string & A, string & B, int n){
	int c = 0;

	int l = 0;
	int r = n-1;
	while (l < r){
		c += mirrorCase(A[l], A[r], B[l], B[r]);
		l += 1;
		r -= 1;
	}
	if (l == r){
		c += middleCase(A[l], B[l]);
	}
	return c;
}

int main(){
	int n;
	string A,B;

	//parsing
	cin >> n;
	cin >> A;
	cin >> B;
	//find solution
	cout << resolve(A,B,n) << "\n";
}
