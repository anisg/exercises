#include <bits/stdc++.h>

using namespace std;

#define LIM (long)(1e9+7)

int sylvester(int n)
{
	long m = 2;

	cout << m;
	for (int i = 1; i < n; i += 1)
	{
		m = (m*(m-1)+1)%LIM;
		cout << " " << m;
	}
}

int main()
{
	int T;

	cin >> T;
	for (int t = 0; t < T; t += 1)
	{
		int a;
		cin >> a;
		sylvester(a);
		cout << endl;
	}
}
