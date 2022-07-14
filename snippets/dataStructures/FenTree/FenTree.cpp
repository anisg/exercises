#include <bits/stdc++.h>

using namespace std;

// FenTree : sum, add, range, get
struct FenTree {
	vector<int> d; int n;
	FenTree(vector<int> & v) : d(vector<int>(n, 0)), n((int)v.size()+1) {
		for (int i=0; i < n-1; i+=1){ d[i+1] = v[i]; }
		for (int i=1; i < n; i+=1){
			int j = i + (i & -i); if (j < n){ d[j] += d[i]; }
		}
	}
	void add(int i, int v){
		i += 1;
		while (i < n){ d[i] += v; i += (i & -i); }
	}
	int sum(int i){
		int r = 0; i += 1;
		while (i > 0){ r += d[i]; i -= (i & -i); }
		return r;
	}
	int range(int l, int r){ return sum(r) - sum(l-1); }
	int get(int i){ return range(i,i); }
};

int main(){
	vector<int> v = {1,2,3,4};
	FenTree d(v);

	cout << d.sum(3) << "\n";
}
