#include <bits/stdc++.h>

using namespace std;

long resolve(vector<int> & A, int n, int top){
	long U, minU, D, maxD;
	U = minU = top;
	D = maxD = 0;

	for (int i = 0; i < n; i += 1){
		if (A[i] > 0)
			D -= A[i];
		else
			U -= A[i];
		if (D < 0){ U += D; D = 0; }
		if (U > top){ D += U - top; U = top; }
		minU = min(minU, U);
		maxD = max(maxD, D);
	}
	if (minU < maxD) return 0;
	return minU - maxD + 1;
}

int main(){
	int n,top;
	vector<int> A;

	//parsing
	cin >> n >> top;
	for (int i = 0; i < n; i += 1){
		int a;
		cin >> a;
		A.push_back(a);
	}
	//find solution
	cout << resolve(A,n, top) << "\n";
}
