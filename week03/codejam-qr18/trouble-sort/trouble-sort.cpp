#include <bits/stdc++.h>

using namespace std;

#define SOLVABLE -1

int isSolvable(int N)
{
	int x;
	vector<int> odd;
	vector<int> even;

	for (int i = 0; i < N; i += 1)
	{
		cin >> x;
		if (i % 2 == 0)
			even.push_back(x);
		else
			odd.push_back(x);
	}

	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());

	int evenSize = (int)even.size();
	int oddSize = (int)odd.size();
	int i = 0;
	int io = 0;
	while (i < evenSize){
		if (io < oddSize && even[i] > odd[io])
			return i + io;
		if (i + 1 < evenSize && odd[io] > even[i+1])
			return i + io + 1;
		i += 1;
		io += 1;
	}
	return SOLVABLE;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1)
	{
		int N;
		cin >> N;
		int r = isSolvable(N);
		cout << "Case #"<< t << ": " << ((r == SOLVABLE) ? "OK" : to_string(r)) << endl;
	}
}
