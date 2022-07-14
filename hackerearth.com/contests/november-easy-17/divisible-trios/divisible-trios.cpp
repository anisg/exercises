#include <bits/stdc++.h>

using namespace std;

bool divisible(size_t n, size_t m){
	return n%m == 0;
}

int resolve(vector<int> & A, int M) {
	int count = 0;
	for (int i = 0; i < A.size(); i += 1)
		for (int j = i+1; j < A.size(); j += 1)
			for (int w = j+1; w < A.size(); w += 1)
				count += divisible(((size_t)A[i])+A[j]+A[w], M);
	return count;
}

int main() {
	int N,M;
	vector<int> A;

	cin >> N >> M;
	for (int n = 0; n < N; n += 1) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	cout << resolve(A,M) << '\n';
}
