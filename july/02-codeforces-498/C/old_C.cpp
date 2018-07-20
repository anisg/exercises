#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int A[2000000+1];

ll resolve(int *A, int n){
	ll m,a,b;
	int l = 0;
	int r = n-1;
	m = 0;
	a = A[l];
	b = A[r];
	while (l != r){
		if (a < b){
			l += 1;
			a += A[l];
		} else if (a > b) {
			r -= 1;
			b += A[r];
		} else {
			m = a;
			l += 1;
			a += A[l];
		}
	}
	return m;
}

int main(){
	int n;

	//parsing
	cin >> n;
	for (int i = 0; i < n; i += 1){
		int a;
		cin >> a;
		A[i] = a;
	}
	//find solution
	cout << resolve(A,n) << "\n";
}
