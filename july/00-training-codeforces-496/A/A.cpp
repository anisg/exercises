#include <bits/stdc++.h>

using namespace std;

void resolve(vector<int> & A, int n){
	vector<int> stairs;

	for (int i = 0; i < n; i += 1){
		if (i+1 >= n || A[i] >= A[i+1])
			stairs.push_back(A[i]);
	}
	//print result
	cout << stairs.size() << "\n";
	for (int i = 0; i < stairs.size(); i += 1){
		cout << stairs[i];
		if (i + 1 < stairs.size())
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
	resolve(A,n);
}
