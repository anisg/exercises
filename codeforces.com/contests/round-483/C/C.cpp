#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> & a){
	int s = 0;
	for (int i = 0; i < a.size(); i += 1){
		s += a[i];
	}
	return s;
}

bool success(int i, int x, int j, int y){
	cout << "YES\n";
	cout << i+1 << " " << x+1 << "\n";
	cout << j+1 << " " << y+1 << "\n";
	return true;
}

bool resolve(vector<vector<int>> & A, int k){
	unordered_map<int,pair<int,int>> m;

	for (int i = 0; i < k; i += 1){
		int s = sum(A[i]);
		vector<int> & a = A[i];
		for (int x = 0; x < a.size(); x += 1){
			if (m.count(s-a[x]) != 0 && m[s-a[x]].first != i)
				return success(m[s-a[x]].first, m[s-a[x]].second, i, x);
			else
				m[s-a[x]] = {i,x};
		}
	}
	return false;
}

int main(){
	int k;
	vector<vector<int>> A;

	cin >> k;
	//parsing
	for (int _ = 0; _ < k; _ += 1){
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i += 1){
			int a;
			cin >> a;
			v.push_back(a);
		}
		A.push_back(v);
	}
	//solving
	if (resolve(A,k) == false)
		cout << "NO\n";
}
