#include <bits/stdc++.h>

using namespace std;

//parse,print
template<typename T> T & parse(T & t){cin >> t; return t;} template<typename T, typename ...Args> void parse(T & t, Args & ...args){parse(t);parse(args...);}
template<typename T> void print(T t) {cout << t << "\n";} template<typename T, typename ...Args> void print(T t, Args ...args){cout << t; print(args...);}

/* ---------------------------------------- */

typedef unordered_map<int,bool> imap;

void dfsInit(int a, imap & v, vector<imap> & adj, vector<imap> & rev, auto & s){
	if (v[a])
		return ;
	v[a] = true;
	for (auto p : adj[a]){
		int b = p.first;
		rev[b][a] = true;
		dfsInit(b,v,adj,rev, s);
	}
	s.push(a);
}

void dfsPrep(int a, imap & v, vector<imap> & adj, int x, auto & um){
	if (v[a])
		return ;
	um[a] = x;
	v[a] = true;
	for (auto p : adj[a]){
		int b = p.first;
		dfsPrep(b, v, adj, x, um);
	}
}

void dfsChange(int a, imap & v, vector<imap> & adj, vector<imap> & merged, auto & um){
	if (v[a])
		return ;
	v[a] = true;
	for (auto p : adj[a]){
		int b = p.first;
		merged[um[a]][um[b]] = true;
		dfsChange(b,v,adj,merged,um);
	}
	merged[um[a]].erase(um[a]);
}

void mergeStrongComponents(vector<int> & ns, vector<imap> & adj, int n){
	stack<int> s;
	vector<imap> rev(n);
	imap v;

	for (int i = 0; i < n; i += 1){
		dfsInit(i, v, adj, rev, s);
	}
	unordered_map<int,int> um;
	v = {};
	while (!s.empty()){
		int x = s.top();
		if (!v[x])
			ns.push_back(x);
		dfsPrep(x, v, rev, x, um);
		s.pop();
	}
	vector<imap> merged(n);
	v = {};
	for (int i = 0; i < ns.size(); i += 1){
		dfsChange(ns[i], v, adj, merged, um);
	}
	adj = merged;
}

int inDegreeZero(vector<int> & ns, vector<imap> & adj){
	imap v; int r = ns.size();
	for (int i = 0; i < ns.size(); i += 1){
		for (auto p : adj[ns[i]]){
			if (!v[p.first])
				v[p.first]=true;
		}
	}
	return r - v.size();
}

int outDegreeZero(vector<int> & ns, vector<imap> & adj){
	int r = 0;
	for (int i = 0; i < ns.size(); i += 1){
		if (adj[ns[i]].size() == 0)
			r += 1;
	}
	return r;
}

int solve(int n, int m){
	vector<int> ns;
	vector<imap> adj(n);

	//get edges
	for (int i = 0; i < m; i += 1){
		int a,b;
		parse(a,b);
		a -= 1; b -= 1;
		if (a != b)
			adj[a][b] = true;
	}
	mergeStrongComponents(ns, adj, n);
	//get number of aditional implications
	if (ns.size() == 1)
		return 0;
	return max(inDegreeZero(ns, adj), outDegreeZero(ns, adj));
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
