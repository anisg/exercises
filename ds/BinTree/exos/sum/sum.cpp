#include <bits/stdc++.h>

using namespace std;

/* ---------------------------------------- */
/* ------------- Data structures ---------- */

//BinTree: sum,update,range,get
struct BinTree {
	vector<int> d; int n;
	BinTree(vector<int> & v) : d(vector<int>(n, 0)), n((int)v.size()+1) {
		for (int i=0; i < n-1; i+=1){ d[i+1] = v[i]; }
		for (int i=1; i < n; i+=1){
			int j = i + (i & -i); if (j < n){ d[j] += d[i]; }
		}
	}
	void update(int i, int add){
		i += 1;
		while (i < n){ d[i] += add; i += (i & -i); }
	}
	int sum(int i){
		int r = 0; i += 1;
		while (i > 0){ r += d[i]; i -= (i & -i); }
		return r;
	}
	int range(int l, int r){ return sum(r) - sum(l-1); }
	int get(int i){ return range(i,i); }
};

/* ---------------------------------------- */
/* -------------   Solution   ------------- */

void resolve(vector<int> & v, int q){
	BinTree b(v);

	for (int _ = 0; _ < q; _ += 1){
		int l,r;
		cin >> l >> r;
		l -= 1; r -= 1;
		cout << b.range(l,r) << endl;
	}
}

int main(){
	int n,q;
	cin >> n;
	vector<int> v;
	for (int i  =0 ; i < n; i += 1){
		int a;
		cin >> a;
		v.push_back(a);
	}
	cin >> q;
	resolve(v, q);
}
