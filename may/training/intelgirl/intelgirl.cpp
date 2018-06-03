#include <bits/stdc++.h>

using namespace std;

bool even(int c)
{
	return (c % 2 == 0);
}

void resolve(string s)
{
	int m = 0;
	for (int i = 0; i < s.size(); i += 1)
		if (even(s[i])) m += 1;
	for (int i = 0; i < s.size(); i += 1) {
		cout << m;
		if (i + 1 < s.size())
			cout << ' ';
		if (even(s[i])) m -= 1;
	}
}

int main()
{
	string s;
	cin >> s;
	resolve(s);
	cout << endl;
}
