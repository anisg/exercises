#include <bits/stdc++.h>

using namespace std;

/* ---------------------------------------- */
/* ------------- Data structures ---------- */

// SegmentTree : update, range
template<typename T> struct SegmentTree {
	vector<T> d; int n; T (*fn)(T a, T b); T zero;
	SegmentTree(vector<T> & v, T (*f)(T a, T b), T z = {}) : n((int)v.size()), fn(f), zero(z) {
		int x = (int)ceil(log2(v.size()));
		d = vector<T>(2*(int)pow(2,x)-1);
		_build(v, 0, n-1, 0);
	}
	T & _build(vector<T> & v, int l, int r, int i){
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
	T _update(int l, int r, int qi, T & val, int i){
		if (l == r && qi == l) return d[i] = val;
		if (l == r || l > qi || r < qi) return d[i];
		int mid = l + (r - l) / 2;
		return d[i] = fn( _update(l,mid, qi, val, 2*i+1), _update(mid+1,r, qi, val, 2*i+2) );
	}
	void update(int i, T val) { _update(0, n-1, i, val, 0); }
	T range(int l, int r) { return _range(0,n-1, l,r, 0); }
};

/* ---------------------------------------- */
/* -------------   Solution   ------------- */

int minimum(int a, int b){ return min(a,b); }

void resolve(vector<int> & v, int n, int q){
	SegmentTree<int> t(v, &minimum, INT_MAX);
	for (int _ = 0; _ < q; _ += 1){
		char c; int l,r,x,y;
		cin >> c;
		if (c == 'q'){
			cin >> l >> r;
			print(t.range(l-1,r-1));
		} else {
			cin >> x >> y;
			t.update(x-1, y);
		}
	}
}

int main(){
	int n,q;
	vector<int> v;

	cin >> n >> q;
	for (int _ = 0; _ < n; _ += 1){
		int a;
		cin >> a;
		v.push_back(a);
	}
	resolve(v, n, q);
}
