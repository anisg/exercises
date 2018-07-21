#include <bits/stdc++.h>

using namespace std;

//parse,print
template<typename T> T & parse(T & t){cin >> t; return t;} template<typename T, typename ...Args> void parse(T & t, Args & ...args){parse(t);parse(args...);}
template<typename T> void print(T t) {cout << t << "\n";} template<typename T, typename ...Args> void print(T t, Args ...args){cout << t; print(args...);}

/* ---------------------------------------- */

typedef unordered_map<int,bool> imap;

void dfsInit(int a, auto & v, auto & adj, auto & s, auto & adj2){
	if (v[a])
		return ;
	v[a] = true;
	for (auto p : adj[a]){
		int b = p.first;
		adj2[b][a] = true;
		dfsInit(b,v,adj,s, adj2);
	}
	s.push(a);
}

void dfsPrint(int a, auto & v, auto & adj){
	if (v[a])
		return ;
	print(a, ", edges:", adj[a].size());
	v[a] = true;
	for (auto p : adj[a]){
		int b = p.first;
		print("       >", b, (v[b] ? " (already visited)" : ""));
		dfsPrint(b,v,adj);
	}
}

void dfsMerge(int a, auto & v, auto & adj, int x, auto & um){
	if (v[a])
		return ;
	um[a] = x;
	v[a] = true;
	for (auto p : adj[a]){
		int b = p.first;
		//swap back by replacing a with x
		dfsMerge(b, v, adj, x, um);
	}
}

void dfsChange(int a, auto & v, auto & adj, auto & adj2, auto & um){
	if (v[a])
		return ;
	v[a] = true;
	for (auto p : adj[a]){
		int b = p.first;
		adj2[um[a]][um[b]] = true;
		dfsChange(b,v,adj,adj2,um);
	}
	adj2[um[a]].erase(um[a]);
}

void mergeStrongComponents(vector<int> & nodes, vector<imap> & adj, int n){
	stack<int> s;
	vector<imap> adj2(n);
	imap v;

	v = {};
	for (int i = 0; i < n; i += 1){
		dfsInit(i, v, adj, s, adj2);
	}

	unordered_map<int,int> um;
	v = {};
	while (!s.empty()){
		int x = s.top();
		if (!v[x])
			nodes.push_back(x);
		dfsMerge(x, v, adj2, x, um);
		s.pop();
	}
	vector<imap> adj3(n);
	v = {};
	for (int i = 0; i < nodes.size(); i += 1){
		dfsChange(nodes[i], v, adj, adj3, um);
	}

	print("--");
	v = {};
	for (int i = 0;i < nodes.size(); i += 1){
		dfsPrint(nodes[i], v, adj3);
	}
	adj = adj3;
}

int countLeaves(int a, vector<imap> & adj, imap & v){
	if (v[a])
		return 0;
	v[a] = true;
	print("node:", a, ", size:", adj[a].size());
	if (adj[a].size() == 0)
		return 1;
	int c = 0;
	for (auto p : adj[a]){
		int b = p.first;
		c += countLeaves(b, adj, v);
	}
	return c;
}

int solve(int n, int m){
	vector<int> nodes;
	vector<imap> adj(n);

	//get edges
	for (int i = 0; i < m; i += 1){
		int a,b;
		parse(a,b);
		a -= 1; b -= 1;
		if (a != b)
			adj[a][b] = true;
	}
	//merge loop nodes
	mergeStrongComponents(nodes, adj, n);
	//get number of aditional implications
	imap v = {};
	int c = 0;
	print("size:",nodes.size());
	int l;
	for (int i = 0; i < nodes.size(); i += 1){
		if (v[nodes[i]])
			continue ;
		l = countLeaves(nodes[i], adj, v);
		c += l;
	}
	if (nodes.size() == 1)
		c -= 1;
	return c;
}

int main(){
	int T;

	parse(T);
	for (int t = 0; t < T; t += 1){
		int n,m;

		parse(n,m);
		print(solve(n,m));
	}
}
