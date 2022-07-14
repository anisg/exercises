#include <bits/stdc++.h>

using namespace std;

struct Plus {
	int a,b,c,d,e;
	int summation(Plus & p){
		return a*p.a + b*p.b + c*p.c + d*p.d + e*p.e;
	}
};

int resolve(vector<vector<int>> & mat, int n, int m){
	vector<Plus> v;
	//creating all possible Plus
	for (int i = 1; i < n-1; i += 1){
		for (int j = 1; j < m-1; j += 1){
			v.push_back({mat[i][j], mat[i][j-1], mat[i][j+1], mat[i-1][j], mat[i+1][j]});
		}
	}
	//find the max summation
	int r = INT_MIN;
	for (int i = 0; i < v.size(); i += 1){
		for (int j = i+2; j < v.size(); j += 1){
			if (j < i + ceil(m/2.0) - 1 || j > i + ceil(m/2.0) + 1)
				r = max(r, v[i].summation(v[j]));
		}
	}
	return r;
}

int main(){
	int n,m;

	cin >> n >> m;
	vector<vector<int>> mat;
	for (int i = 0; i < n; i += 1){
		vector<int> x;
		for (int j = 0; j < m; j += 1){
			int a;
			cin >> a;
			x.push_back(a);
		}
		mat.push_back(x);
	}
	cout << resolve(mat,n,m) << '\n';
}
