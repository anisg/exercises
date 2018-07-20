#include <bits/stdc++.h>

using namespace std;

bool cmp_val(pair<int,int> & a, pair<int,int> & b){
	return a.first > b.first;
}

bool cmp_pos(pair<int,int> & a, pair<int,int> & b){
	return a.second < b.second;
}

int resolve(vector<pair<int,int>> & X, int n, int k){
	sort(X.begin(), X.end(), &cmp_val);
	sort(X.begin(), X.begin() + k, &cmp_pos);

	size_t m = 0;
	for (int i = 0; i < k; i += 1){
		m += (size_t)X[i].first;
	}
	cout << m << "\n";
	int p,nb;
	nb=p=0;
	for (int i = 0; i < k; i += 1){
		nb = (X[i].second-p) + 1;
		p = X[i].second+1;
		if (i + 1 == k) nb += n-X[i].second-1;
		cout << nb;
		cout << ((i + 1 >= k) ? "\n" : " ");
	}
}

int main(){
	int n, k;
	vector<pair<int,int>> X;

	//parsing
	cin >> n >> k;
	for (int i = 0; i < n; i += 1){
		int a;
		cin >> a;
		X.push_back({a,i});
	}
	//find solution
	resolve(X,n,k);
}
