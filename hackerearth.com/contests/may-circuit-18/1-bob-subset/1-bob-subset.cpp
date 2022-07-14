#include <bits/stdc++.h>

using namespace std;

int resolve(vector<int> A, int n, int k){
	unordered_map<int,bool> mp;
	vector<int> B;
	if (k == 1)
		return n;
	for (int i = 0; i < n; i += 1){
		for (int j = i+1; j < n; j += 1){
			if (mp.count(A[i] | A[j]) == 0){
				mp[A[i] | A[j]] = true;
				B.push_back(A[i] | A[j]);
			}
		}
		mp[A[i]] = true;
		B.push_back(A[i]);
	}
	return resolve(B, B.size(), k-1);
}

int main(){
	int n, k;
	cin >> n >> k;

	unordered_map<int,bool> mp;
	vector<int> A;
	for (int _ = 0; _ < n; _ += 1){
		int a;
		cin >> a;
		if (mp.count(a) == 0){
			mp[a] = true;
			A.push_back(a);
		}
	}
	cout << resolve(A,A.size(),k) << endl;
}
