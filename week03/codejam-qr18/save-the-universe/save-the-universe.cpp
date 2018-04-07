#include <bits/stdc++.h>

using namespace std;

int solve(int D, string & s)
{
	unsigned n = 0;
	unsigned vm = 1;
	unsigned m = 0;

	for (size_t i = 0; i < s.size(); i += 1)
	{
		if (s[i] == 'S'){
			n += 1;
			m += vm;
		}
		else
			vm = (vm << 1);
	}
	if (n > D) return -1;
	if (m <= D) return 0;
	unsigned v;
	n = 0;
	while (m > D)
	{
		v = vm;
		for (int i = (int)s.size()-1; i >= 0; i -= 1)
		{
			if (i + 1 < (int)s.size() &&
				s[i] == 'C' && s[i + 1] == 'S')
			{
				m -= v/2;
				s[i] = 'S';
				s[i+1] = 'C';
				break;
			}
			if (s[i] == 'C')
				v = (v >> 1);
		}
		n += 1;
	}
	return n;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t+=1)
	{
		int D;
		string s;
		int r;

		cin >> D >> s;
		r = solve(D, s);
		cout << "Case #" << t << ": " << (r == -1 ? "IMPOSSIBLE" : to_string(r)) << endl;
	}
}
