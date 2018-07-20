#include <bits/stdc++.h>

using namespace std;

void printSolution(vector<int> & A, int n){
	//update array
	for (int i = 0; i < n; i += 1){
		if (A[i] % 2 == 0)
			A[i] -= 1;
	}
	//print
	for (int i = 0; i < n; i += 1){
		cout << A[i];
		if (i+1<n)
			cout << " ";
	}
	cout << "\n";
}

int main(){
	int n;
	vector<int> A;

	//parsing
	cin >> n;
	for (int i = 0; i < n; i += 1){
		int a;
		cin >> a;
		A.push_back(a);
	}
	//find solution
	printSolution(A,n);
}
