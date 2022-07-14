#include <bits/stdc++.h>

using namespace std;

size_t resolve(string & s)
{
	size_t count = 0;
	size_t j = 0;
	for (size_t i = 0; i < s.length(); i += 1)
	{
		if (s[i] == 'a' || s[i] == 'z'){
			size_t m = (i - j) + 1;
			count += m * (s.length()-i);
			j = i + 1;
		}
	}
	return count;
}

int main()
{
	int T;
	cin >> T;
	for (int _ = 0; _ < T; _ += 1){
		string s;
		cin >> s;

		cout << resolve(s) << endl;
	}
}
