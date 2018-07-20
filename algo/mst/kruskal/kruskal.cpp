#include <bits/stdc++.h>

using namespace std;

/* ---------------------------------------- */
/* -------------     Debug       ---------- */

//operator '<<' on vector
template <typename T> ostream& operator<<(ostream& os, vector<T> & v) { os << "["; for (size_t i = 0; i < v.size(); i += 1){ os << v[i]; if (i + 1 < v.size()) os << ", "; } os << "]"; return os; }

/* ---------------------------------------- */
/* -------------     Ds          ---------- */

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
/* -------------    Solution     ---------- */

struct Edge { int u,v; int w;
	static bool byWeight(Edge & a, Edge & b){ return a.w < b.w; }
	friend ostream& operator<<(ostream& os, Edge e) { return os << "(" << e.u << "<->" << e.v << ")"; }
};

struct Graph {
	vector<int> V;
	vector<Edge> E;
};

//Kruskal implementation using a disjoint set
vector<Edge> mst(Graph & G){
	vector<Edge> A;
	UnionFind<int> sets(G.V.size());

	sort(G.E.begin(), G.E.end(), &Edge::byWeight);
	for (Edge & e : G.E){
		if (sets.find(e.u) != sets.find(e.v)){
			A.push_back(e);
			sets.join(e.u, e.v);
		}
	}
	return A;
}

int main(){
	/*
		(0)--2--(1)--10
		 |       |     \
		 7       1     (4)
		 |       |     /
		(2) -9- (3)--1/
	*/
	Graph G = {
		{0,1,2,3,4},//5 vertices
		{{0,1,2}, {0,2,7}, {1,3,1}, {1,4,10}, {2,3,9}, {3,4,1}} //6 edges
	};

	auto A = mst(G);
	for (auto & e : A){ cout << e << "\n"; }
	/*
		(0)--2--(1)
		 |       |
		 7       1     (4)
		 |       |     /
		(2)     (3)--1/
	*/
}
