#include <bits/stdc++.h>

using namespace std;

/* idea: create a beautiful array of the 3 first elems           */
/*       if an item is sup than the last one, insert by shifting */
size_t resolve(vector<int> & A) {
	size_t b[3];

	b[0] = A[0];
	b[1] = A[1];
	b[2] = A[2];
	for (int i = 3; i < A.size(); i += 1){
		if (A[i] >= b[2]){
			b[0] = b[1]; b[1] = b[2]; b[2] = A[i];
		}
	}
	return b[0] * b[1] * b[2];
}

int main() {
	int N;
	vector<int> A;

	cin >> N;
	for (int _ = 0; _ < N; _ += 1) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	cout << resolve(A) << '\n';
}
