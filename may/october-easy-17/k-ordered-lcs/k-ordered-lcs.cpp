#include <bits/stdc++.h>
using namespace std;

/* naive lcs implementation wich return an index */
vector<pair<int,int>> naive_lcs(vector<int> & s1, vector<int> & s2, int m, int n) {
	if (s1.size() == m || s2.size() == n)
		return {};

	if (s1[m] == s2[n]) {
		vector<pair<int,int>> v = { {m,n} };
		auto tmp = naive_lcs(s1, s2, m+1, n+1);
		v.insert(end(v), begin(tmp), end(tmp));
		return v;
	} else {
		vector<pair<int,int>> v1;
		vector<pair<int,int>> v2;
		v1 = naive_lcs(s1, s2, m+1, n);
		v2 = naive_lcs(s1, s2, m, n+1);
		if (v1.size() >= v2.size())
			return v1;
		return v2;
	}
}

int resolve(vector<int> & s1, vector<int> & s2, int k) {
	//compute lcs
	for (int _ = 0; _ < s1.size(); _ += 1) {
		cout << s1[_] << ':';
	} cout << '\n';

	vector<pair<int,int>> b = naive_lcs(s1, s2, 0,0);

	for (int i = 0; i < b.size(); i+=1) {
		cout << b[i].first << "&" << b[i].second << endl;
	}
	return (0);
}

int main() {
	int N,M,k;
	vector<int> s1, s2;

	cin >> N >> M >> k;
	int a;
	for (int _ = 0; _ < N; _ += 1) {
		cin >> a;
		s1.push_back(a);
	}
	for (int _ = 0; _ < M; _ += 1) {
		cin >> a;
		s2.push_back(a);
	}
	cout << resolve(s1, s2, k) << '\n';
	print(resolve);
}
