#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> A;
vector<pair<int,int>> ids;

int visit(int i){
	int c;

	ids[i] = {A.size(), 0};
	A.push_back(i);
	c = 0;
	for (int & x : adj[i]){
		c += visit(x);
	}
	ids[i].second = 1+c;
	return 1 + c;
}

void resolve(int n, int k){
	//dfs
	ids.reserve(n+1);
	visit(1);
	//answer queries
	for (int i = 0; i < k; i += 1){
		int u,k;
		cin >> u >> k;
		if (ids[u].second < k)
			cout << "-1\n";
		else
			cout << A[ids[u].first + k - 1] << "\n";
	}
}

int main(){
	int n,k;

	//parsing
	cin >> n >> k;
	for (int i = 0; i <= n; i += 1){
		adj.push_back({});
	}
	for (int i = 2; i <= n; i += 1){
		int a;
		cin >> a;
		adj[a].push_back(i);
	}
	//find solution
	resolve(n, k);
}
