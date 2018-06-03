#include <bits/stdc++.h>

using namespace std;

// SegmentTree : ...
template<typename T> struct SegmentTree {
	vector<T> d; int n; int c; T (*fn)(T a, T b); T zero;
	SegmentTree(vector<T> v, T (*f)(T a, T b), T z = {}) : n((int)v.size()), fn(f), zero(z) {
		int x = (int)ceil(log2(v.size()));
		c = 2*(int)pow(2,x)-1;
		d = vector<T>(c);
		_build(v, 0, n-1, 0);
	}
	T & _build(vector<T> v, int l, int r, int i){
		if (l == r) return d[i] = v[l];
		int mid = l + (r - l) / 2;
		return d[i] = fn( _build(v, l, mid, 2*i+1), _build(v, mid+1, r, 2*i+2) );
	}
	T _range(int l, int r, int ql, int qr, int i) {
		if (l >= ql && r <= qr) return d[i];
		if (l > qr || r < ql) return zero;
		int mid = l + (r - l) / 2;
		return fn( _range(l,mid, ql,qr, 2*i+1), _range(mid+1,r, ql,qr, 2*i+2) );
	}
	T range(int l, int r) { return _range(0,n-1, l,r, 0); }
};

int sum(int a, int b){ return a + b; }

int main(){
	SegmentTree<int> t({1,2,3,4,5}, &sum);

	cout << t.range(1,3) << "\n";
}
