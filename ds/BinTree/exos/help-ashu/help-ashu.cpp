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

bool isOdd(int v){
	if (v % 2 == 0) return false;
	return true;
}

void resolve(vector<int> & odds, int q){
	BinTree b(odds);

	for (int _ = 0; _ < q; _ += 1){
		int k,i,x,l,r;
		cin >> k;
		if (k == 0){
			cin >> i >> x;
			i -= 1;
			if (isOdd(x) && b.get(i) == 0)
				b.update(i, 1);
			if (!isOdd(x) && b.get(i) == 1)
				b.update(i, -1);
		}
		if (k == 1){
			cin >> l >> r;
			l -= 1; r -= 1;
			cout << (r-l+1)-b.range(l,r) << "\n";
		}
		if (k == 2){
			cin >> l >> r;
			l -= 1; r -= 1;
			cout << b.range(l,r) << "\n";
		}
	}
}

int main(){
	int n, q;
	vector<int> odds;

	cin >> n;
	for (int i = 0; i < n; i += 1){
		int a;
		cin >> a;
		odds.push_back(isOdd(a));
	}
	cin >> q;
	resolve(odds, q);
}
