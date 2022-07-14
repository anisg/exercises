#include <bits/stdc++.h>

using namespace std;

int leadingZeros(string & s, int p){
	int c = 0;

	p--;
	while (p >= 0 && s[p] == '0'){
		p--;
		c++;
	}
	return c;
}

string convert(long long n)
{
	string s("");

	while (n) {
		s += (n & 1) + '0';
		n /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

int resolve(string & s, long long C, long long P)
{
	int count = 0;
	string c = convert(C);
	string p = convert(P);

	int l = 0;
	int r = 0;
	while ((l = s.find(c, l)) != -1){
		if ((r = s.find(p, l+c.size()+1)) == -1)
			break ;
		int tmp = leadingZeros(s, r);
		if (tmp > r - (l+c.size()) ){
			count += 1 + leadingZeros(s, l);
		} else if (tmp == r - (l+c.size())){
			count += tmp + leadingZeros(s, l);
		}
		l += 1;
	}
	return count;
}

int main()
{
	string s;
	long long C,P;

	cin >> s;
	cin >> C >> P;
	cout << resolve(s, C, P) << endl;
}
