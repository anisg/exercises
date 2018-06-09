#include <bits/stdc++.h>

using namespace std;

int R[200000+1];
int S[200000+1];
int skip[200000+1];

int cmp(void *a, void *b){ return (*(int*)a) - (*(int*)b); }

int resolve(int *A, int n, unordered_map<pair<int,int>,bool> & m){
	for (int i = 1; i <= n; i += 1){
		S[i] = R[i];
	}
	sort(S+1, S+1+n);
	//sligthy optimization
	prev = -1;
	for (int i = 1; i <= n; i += 1){
		if (i > 1 && skip[i] > skip[i-1])
			prev = i-1;
		skip[i] = prev;
	}
	for (int i = 1; i <= n; i += 1){
		int x = bsearch(&R[i], S+1, n, sizeof(int), cmp);
		x = skip[x];
		while (x > 0){
			if (m.count({min(a,b),max(a,b)}) == 0){
				cout << S
			}
			x--;
		}
		if (x <= 0)
			cout << "0\n";
	}
}

int main(){
	int n, k;

	//parsing
	cin >> n >> k;
	for (int i = 1; i <= n; i += 1){
		int a;
		cin >> a;
		R[i] = A;
	}
	for (int _ = 1; _ <= k; _ += 1){
		int a,b;
		cin >> a >> b;
		m[{min(a,b),max(a,b)}] = true;
	}
	//find solution
	cout << resolve(A,n) << "\n";
}
