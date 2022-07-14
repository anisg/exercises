#include <bits/stdc++.h>

using namespace std;

int dy[1000000+2];
int m = 0;

int countBits(unsigned long long n)
{
	int c = 0;
	while (n)
	{
		//if (n & 1)
		//	c += 1;
		c += 1;
		n /= 2;
	}
	return c;
}

int countNoDividOverflow(unsigned long long & a)
{
	if (a <= m)
		return dy[a];
	int count = dy[m];
	for (unsigned long long d = m+1; d <= a; d += 1)
	{
		if (countBits(a/d) < countBits(d))
			count += 1;
		dy[m] = count;
	}
	dy[a] = count;
	m = a;
	return count;
}

int main()
{
	int T;

	dy[0] = 0;
	cin >> T;
	for (int t = 0; t < T; t += 1)
	{
		unsigned long long a;
		cin >> a;
		cout << countNoDividOverflow(a) << endl;
	}
}
