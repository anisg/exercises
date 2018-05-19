#include <bits/stdc++.h>

using namespace std;

size_t fact(size_t nb){
	return tgamma(nb+1);
}

size_t resolve(vector<int> & levels) {
	size_t r = 1;
	for (int i = 0; i < levels.size(); i += 1){
		r *= fact(levels[i]) % 666013;
	}
	return r;
}

int main() {
	int N,M;
	vector<int> levels;
	int *n = new int[1000000+1]();

	cin >> N >> M;
	levels.push_back(N);
	for (int m = 0; m < M; m += 1) {
		int x,y;
		cin >> x >> y;
		for (int i = x; i <= y; i+=1) {
			levels[n[i]] -= 1;
			n[i] += 1;
			if (levels.size() == n[i])
				levels.push_back(1);
			else
				levels[n[i]] += 1;
		}
	}
	cout << resolve(levels) << endl;
}
