#include <bits/stdc++.h>

using namespace std;

int sub(vector<vector<int>> & v, int y, int x, int l){
	int sum = 0;
	if (y+l > v.size() || x+l > v[y].size())
		return INT_MIN;
	for (int i = 0; i < l; i += 1){
		for (int j = 0; j < l; j += 1){
			sum += v[y+i][x+j];
		}
	}
	return sum;
}

int maxsub(vector<vector<int>> & v)
{
	int m = INT_MIN;
	for (int y = 0; y < v.size(); y += 1){
		for (int x = 0; x < v[y].size(); x += 1){
			for (int l = 1; l <= v.size(); l += 1){
				m = max(sub(v, y, x, l), m);
			}
		}
	}
	return m;
}

int main()
{
	int N,M;
	vector<vector<int>> v;
	int count = 0;

	cin >> N >> M;
	for (int n = 0; n < N; n += 1){
		vector<int> tmp;
		for (int m = 0; m < M; m += 1){
			int c;
			cin >> c;
			if (c == 1) {
				count += 1;
				c = -1;
			} else
				c = 1;
			tmp.push_back(c);
		}
		v.push_back(tmp);
	}
	cout << count + maxsub(v) << endl;
}
