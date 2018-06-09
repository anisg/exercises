#include <bits/stdc++.h>

using namespace std;

void resolve(vector<int> & A, int n){
	unordered_map<int,bool> m;
	vector<int> v;
	for (int i = n-1; i >= 0; i -= 1){
		if (!m.count(A[i])){
			m[A[i]] = true;
			v.push_back(A[i]);
		}
	}
	//printing
	cout << v.size() << "\n";
	for (int i = v.size()-1; i >= 0; i -= 1){
		cout << v[i];
		if (i - 1 >= 0)
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
