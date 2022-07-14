#include <bits/stdc++.h>

using namespace std;

size_t A[200000+1];
size_t B[200000+1];
int binarySearch(size_t *A, int n, size_t c){
	int l = 0;
	int r = n-1;
	while (true){
		int m = l + (r-l) / 2;
		if (c <= A[l])
			return l;
		if (m == l)
			return r;
		if (c > A[m])
			l = m;
		if (c < A[m])
			r = m;
	}
	return -1;
}

void resolve(size_t *A, int n, size_t *B, int m){
	for (int i = 0; i < m; i += 1){
		int x = binarySearch(A, n, B[i]);
		size_t nb = (x > 0) ? B[i] - A[x-1] : B[i];
		cout << x+1 << " " << nb << "\n";
	}
}

int main(){
	int n,m;

	//parsing + modification (add prev sum to nb)
	cin >> n >> m;
	size_t sum = 0;
	for (int i = 0; i < n; i += 1){
		size_t a;
		cin >> a;
		sum += a;
		A[i] = sum;
	}
	for (int i = 0; i < m; i += 1){
		size_t b;
		cin >> b;
		B[i] = b;
	}
	//find solution
	resolve(A,n,B,m);
}
