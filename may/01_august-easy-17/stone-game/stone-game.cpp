#include <bits/stdc++.h>

using namespace std;

string winner(vector<int> & A, int l, int r)
{
	if (r-l+1 == 1)
		return "Phineas";
	int sum = 0;
	for (int i = l; i <= r; i += 1)
		sum += A[i-1];
	if (sum % 2 == 0)
		return "Phineas";
	return "Ferb";
}

int main()
{
	int N;
	vector<int> A;

	cin >> N;
	for (int n = 0; n < N; n += 1){
		int a;
		cin >> a;
		A.push_back(a);
	}
	int Q;
	cin >> Q;
	for (int q = 0; q < Q; q += 1)
	{
		int l,r;
		cin >> l >> r;
		cout << winner(A, l, r) << endl;
	}
}
