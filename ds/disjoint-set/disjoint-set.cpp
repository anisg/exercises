#include <bits/stdc++.h>

using namespace std;

/*
	simple UnionFind template
	- join a b : merge a and b together.
	- set x : return the set of x
	note: typename must overload `+=` to work correctly
*/
template<typename T> struct UnionFind {
	vector<int> p; vector<T> sets;
	UnionFind(int n, T (*f)(int i) = nullptr){
		for (int i = 0; i < n; i += 1){
			p.push_back(i);
			(f == nullptr) ? sets.push_back({}) : sets.push_back(f(i));
		}
	}
	T & set(int a){ return sets[find(a)]; }
	int find(int a){
		if (p[a] == a) return a;
		return p[a] = find(p[a]);
	}
	bool join(int a, int b){
		a = find(a); b = find(b);
		if (a == b) return false;
		p[b] = p[a];
		sets[a] += sets[b];
		return true;
	}
};

int init(int i){
	return i;
}

int main(){
	UnionFind<int> sets(5, &init);
	sets.join(0,1);
	sets.join(0,2);
	for (int i = 0; i < 5; i += 1){
		cout << sets.set(i) << "\n";
	}
}
