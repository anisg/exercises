#include <bits/stdc++.h>

using namespace std;

int resolve(int *a, int N, int L, int R) {
	if (L > N)
		return 0;
	if (R > N)
		R = N;
	return a[R] - a[L];
}

bool k_reachable(int k, int x, string & rep) {
	int d = 0;
	int l = rep.size();
	int i = 0;
	while (x){
		if (!(rep[l-i-1] - '0' == x % 10))
			d += 1;
		i += 1;
		x /= 10;
	}
	d += (l-i);
	return d <= k;
}

int main() {
	int N,k,Q;

	cin >> N >> k >> Q;
	//get Nlim
	int Nlim = N + (10-N%10);
	//precompute from 1 to N
	int *a = new int[Nlim + 1];
	string rep = to_string(N);
	a[0] = 0;
	for (int i = 1; i <= Nlim; i += 1) {
		a[i] = a[i-1] + k_reachable(k, i, rep);
	}
	//answer each queries
	for (int q = 0; q < Q; q += 1) {
		int L,R;
		cin >> L >> R;
		cout << resolve(a, Nlim, L, R) << '\n';
	}
}
