#include <bits/stdc++.h>

using namespace std;

//parse,print
template<typename T> T & parse(T & t){cin >> t; return t;} template<typename T, typename ...Args> void parse(T & t, Args & ...args){parse(t);parse(args...);}
template<typename T> void print(T t) {cout << t;} template<typename T, typename ...Args> void print(T t, Args ...args){print(t);print(args...);}

/* ---------------------------------------- */
/* ------------- Data structures ---------- */

// UnionFind : join, set, find
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

typedef long long ll;
#define MAX 100001
#define lim 1000000007

ll f[MAX];
int fn = 0;

ll     fact(int a){
	if (fn == 0){
		f[1] = 1;
		fn = 2;
		while (fn <= MAX){
			f[fn] = (fn * f[fn-1]) % lim;
			fn += 1;
		}
	}
	return f[a];
}

int init(int i){return 1;}

int resolve(int n, int k){
	UnionFind<int> u(n, &init);

	for (int _ = 0; _ < k; _ += 1){
		int a,b;
		parse(a,b);
		u.join(a,b);
	}
	unordered_map<int,bool> m;
	ll r = 1;
	for (int i = 0; i < n; i += 1){
		if (m[u.find(i)] == true)
			continue ;
		r = (r*fact(u.set(i))) % lim;
		m[u.find(i)] = true;
	}
	return r;
}

int main(){
	int n, k;

	parse(n, k);
 	print(resolve(n,k), "\n");
}
