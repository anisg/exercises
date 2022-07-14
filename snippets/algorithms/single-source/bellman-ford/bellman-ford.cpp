#include <bits/stdc++.h>

using namespace std;

/* ---------------------------------------- */
/* -------------     Debug       ---------- */

//operator '<<' on vector
template <typename T> ostream& operator<<(ostream& os, vector<T> & v) { os << "["; for (size_t i = 0; i < v.size(); i += 1){ os << v[i]; if (i + 1 < v.size()) os << ", "; } os << "]"; return os; }

/* ---------------------------------------- */
/* -------------    Solution     ---------- */

struct Edge { int u,v; int w;
	static bool byWeight(Edge & a, Edge & b){ return a.w < b.w; }
	friend ostream& operator<<(ostream& os, Edge e) { return os << "(" << e.u << "<->" << e.v << ")"; }
};

struct Vertice {
	int n;
	Vertice *r;
	int d;
	Vertice(int n) : n(n), r(nullptr), d(0) {}
};

struct Graph {
	vector<Vertice> V;
	vector<Edge> E;

	//initPath(){}
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
		{Vertice(0),Vertice(1),Vertice(2),Vertice(3),Vertice(4)},//5 vertices
		{{0,1,2}, {0,2,7}, {1,3,1}, {1,4,10}, {2,3,9}, {3,4,1}} //6 edges
	};

	/*
		(0)--2--(1)
		 |       |
		 7       1     (4)
		 |       |     /
		(2)     (3)--1/
	*/
}
