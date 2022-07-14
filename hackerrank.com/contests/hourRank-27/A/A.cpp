#include <bits/stdc++.h>

using namespace std;

bool resolve(vector<int> & A, int n){
	bool d = false;
	for (int i = 1; i < n; i += 1){
		if (A[i-1] > A[i]){
			if (d)
				return false;
			//2 case
			if (i-1 == 0 || (i >= 2 && A[i-2] <= A[i]))
				A[i-1] = A[i];
			else
				A[i] = A[i-1];
			d = true;
		}
	}
	return true;
}

int p(){
	int n;
	vector<int> A;

	//parsing
	cin >> n;
	A.reserve(n);
	for (int i = 0; i < n; i += 1){
		int a;
		cin >> a;
		A[i] = a;
	}
	//find solution
	cout << (resolve(A,n) ? "YES" : "NO") << "\n";
}


int main(){
	int t;

	cin >> t;
	for (int i = 0; i < t; i += 1){
		p();
	}
}
