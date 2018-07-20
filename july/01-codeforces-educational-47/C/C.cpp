#include <bits/stdc++.h>

using namespace std;

double resolve(int n, vector<pair<int,int>> & A, int m){
	vector<int> r(n);
	for (int i = 0; i < m; i += 1){
		int x = A[i].first;
		int d = A[i].second;
		int j;
		if (d == 0 && x == 0)
			continue ;
		if (d < 0)
			j = n/2-1;
		else
			j = n-1;
		for (int b = 0; b < n; b += 1)
			r[b] += x + d*abs(j-b);
	}
	double res;
	for (int b = 0; b < n; b += 1)
		res += r[b];
	return res/n;
}

int main(){
	int n, m;
	vector<pair<int,int>> A;

	//parsing
	cin >> n >> m;
	for (int i = 0; i < m; i += 1){
		int x,d;
		cin >> x >> d;
		A.push_back({x,d});
	}
	//find solution
	cout << std::setprecision(7) << resolve(n, A, m) << "\n";
}
