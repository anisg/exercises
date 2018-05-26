#include <bits/stdc++.h>

using namespace std;

int A[100000+1];

void swapPtr(unordered_map<int,int> **pm1, unordered_map<int,int> **pm2){
	unordered_map<int,int> *tmp;
	tmp = (*pm1);
	(*pm1) = (*pm2);
	(*pm2) = tmp;
}

size_t resolve(int *A, int n, int m, int k){
	unordered_map<int,int> m1,m2;
	unordered_map<int,int> *map = &m1;
	unordered_map<int,int> *mn = &m2;

	int sol = 0;
	for (int i = 0; i < n; i += 1){
		for (pair<int, int>e : (*map)) {
			int n = ((size_t)e.first * A[i]) % (size_t)m;
			if (n == k){
				sol += e.second;
			}
			if ((*mn).count(n) == 0)
				(*mn)[n] = e.second;
			else
				(*mn)[n] += e.second;
			e.second = 0;
		}
		if (A[i] % m == k){
			sol += 1;
		}
		if ((*mn).count(A[i] % m) == 0)
			(*mn)[A[i] % m] = 1;
		else
			(*mn)[A[i] % m] += 1;
		swapPtr(&map, &mn);
	}
	return sol;
}

int main(){
	int T;

	cin >> T;
	for (int t = 0; t < T; t += 1){
		//parse each query
		int n,m,k;
		cin >> n >> m >> k;
		int a;
		for (int i = 0; i < n; i += 1){
			cin >> a;
			A[i] = a;
		}
		cout << resolve(A, n, m, k) << '\n';
	}
}
