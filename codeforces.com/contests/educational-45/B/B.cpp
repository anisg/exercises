#include <bits/stdc++.h>

using namespace std;

int A[200000+1];
int B[200000+1];
int C[200000+1];

int resolve(int *A, int n, int k){
	sort(A, A+n);
	int m = 0;
	B[m] = A[0];
	C[m] = 1;
	//making array
	for (int i = 1; i < n; i += 1){
		if (A[i-1] == A[i])
			C[m] += 1;
		else {
			m += 1;
			B[m] = A[i];
			C[m] = 1;
		}
	}
	m += 1;
	int total = n;
	//resolving
	for (int i = 1; i < m; i += 1){
		if (B[i] <= B[i-1] + k){
			total -= C[i-1];
		}
	}
	return total;
}

int main(){
	int n,k;

	//parsing
	cin >> n >> k;
	for (int i = 0; i < n; i += 1){
		int a;
		cin >> a;
		A[i] = a;
	}
	//find solution
	cout << resolve(A,n,k) << "\n";
}
