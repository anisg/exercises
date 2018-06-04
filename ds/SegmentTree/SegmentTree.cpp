#include <bits/stdc++.h>

using namespace std;

// SegmentTree : update, range
template<typename T> struct SegmentTree {
	vector<T> d; int n; T (*fn)(T a, T b); T zero;
	SegmentTree(vector<T> v, T (*f)(T a, T b), T z = {}) : n((int)v.size()), fn(f), zero(z) {
		int x = (int)ceil(log2(v.size()));
		d = vector<T>(2*(int)pow(2,x)-1);
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
	T _update(int l, int r, int qi, T & val, int i){
		if (l == r && qi == l) return d[i] = val;
		if (l == r || l > qi || r < qi) return d[i];
		int mid = l + (r - l) / 2;
		return d[i] = fn( _update(l,mid, qi, val, 2*i+1), _update(mid+1,r, qi, val, 2*i+2) );
	}
	void update(int i, T val) { _update(0, n-1, i, val, 0); }
	T range(int l, int r) { return _range(0,n-1, l,r, 0); }
};

int sum(int a, int b){ return a + b; }
//int maximum(int a, int b){ return max(a,b); }

int main(){
	SegmentTree<int> t({0,1,2,3,4}, &sum);

	cout << t.range(1,3) << "\n";
	cout << t.range(0,2) << "\n";
	cout << t.range(0,1) << "\n";
	cout << t.range(0,0) << "\n";
	t.update(0, 5);
	cout << "Update" << "\n";
	cout << t.range(0,0) << "\n";
	cout << t.range(0,1) << "\n";
	cout << t.range(0,2) << "\n";
}
