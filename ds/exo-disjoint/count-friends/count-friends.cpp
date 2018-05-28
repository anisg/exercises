#include <bits/stdc++.h>

using namespace std;

/* ---------------------------------------- */
/* ------------- Data structures ---------- */

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

int init(int i){return 1;}

string resolve(int N, int M){
	UnionFind<int> u(N, &init);

	//parse query
	for (int i = 0; i < M; i += 1){
		int x,y;
		cin >> x >> y;
		u.join(x-1,y-1);
	}
	string s = "";
	for (int i = 0; i < N; i += 1){
		s += to_string(u.set(i) - 1);
		if (i + 1 < N) s += " ";
	}
	return s;
}

int main(){
	int N, M;

	cin >> N >> M;
	cout << resolve(N,M) << '\n';
}
