#include <bits/stdc++.h>

using namespace std;

int resolve(vector<int> & v, int n)
{
	int m;
	int i;

	m = __gcd(v[n-1], v[n-2]);
	for (i = n-2; i >= 0; i--)
	{
		if (__gcd(v[i],m) <= m)
			break ;
	}
	return i+1;
}

int main()
{
	int n;
	vector<int> v;

	cin >> n;
	for (int _ = 0; _ < n; _ += 1)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	cout << resolve(v, n) << endl;
}
