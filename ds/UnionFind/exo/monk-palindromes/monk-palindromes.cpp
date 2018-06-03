#include <bits/stdc++.h>

using namespace std;

#define lim 1000000007

/* ---------------------------------------- */
/* ------------- Data structure  ---------- */

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

/* ---------------------------------------- */
/* -------------   Solution   ------------- */

int init(int i){ return 1; }

int resolve(int n, int q){
	UnionFind<int> u(n, &init);

	//resolve queries
	for (int _=0; _<q;_++){
		int a,b;
		cin >> a >> b;

		int m = (b-a)/2;
		for (int i = 0; i <= m; i += 1){
			u.join(a+i, b-i);
		}
	}
	//find solution
	size_t answer = 1;
	for (int i = 0; i < n; i += 1){
		if (u.p[i] == i)
			answer = (answer * 10) % lim;
	}
	return answer;
}

int main(){
	int n, q;

	cin >> n;
	cin >> q;
	cout << resolve(n,q) << '\n';
}
