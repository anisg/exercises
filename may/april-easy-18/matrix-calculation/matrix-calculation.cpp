#include <bits/stdc++.h>

using namespace std;

#define LIM (long)(1e9+7)

int look[20+1][20+1];

int find(int N, int n, int *used, long q)
{
	long count = 0;
	if (N == n)
		return q;
	for (int i = 0; i < N; i += 1){
		if (used[i] == false) {
			used[i] = true;
			count = (count + find(N, n+1, used, (q*look[n][i]) % LIM)) % LIM;
			used[i] = false;
		}
	}
	return count;
}

int resolve(int N, int M)
{
	int *used = new int[N]();
	return find(N, 0, used, 1);
}

int main()
{
	int N,M;

	cin >> N >> M;
	for (int n = 0; n < N; n += 1) {
		for (int i = 0; i < N; i += 1)
			look[n][i] = 0;
		for (int m = 0; m < M; m += 1) {
			int a;
			cin >> a;
			look[n][a] += 1;
		}
	}
	cout << resolve(N,M) << endl;
}
