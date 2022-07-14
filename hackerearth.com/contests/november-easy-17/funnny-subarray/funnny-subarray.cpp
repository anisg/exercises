#include <bits/stdc++.h>

using namespace std;

int max_funny_subarray(vector<int> & v) {
	unordered_map<int,int> m;
	int ret = INT_MIN;

	for (int i = 0; i < v.size(); i ++){
		if (m.count(v[i]) == 0) {
			m[v[i]] = i;
		}
		ret = max(ret, i- m[v[i]] +1);
	}
	return ret;
}

int main() {
	int N;
	vector<int> v;

	cin >> N;
	for (int n = 0; n < N; n += 1)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	cout << max_funny_subarray(v) << endl;
}
