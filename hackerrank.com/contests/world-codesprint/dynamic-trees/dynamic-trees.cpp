#include <bits/stdc++.h>

using namespace std;
struct Node{
	unordered_map<int,bool> cs;
	int parent;
	int black;
	int level;
	bool color;
};

Node adj[100000+1];
int	bs[100000+1];
int	rs[100000+1];

int kthBlack(int a, int b, int k){
	bool reverse = false;
	int bn = 0;
	if (adj[a].level < adj[b].level){
		reverse = true;
		swap(a,b);
	}
	//get same level as b
	while (adj[a].level != adj[b].level){
		if (adj[a].color == 1){
			bs[bn++] = a;
		}
		a = adj[a].parent;
	}

	if (a == b && adj[a].color == 1){
		bs[bn++] = a;
	}
	int rn = 0;
	while (a != b){
		if (adj[a].color == 1){
			bs[bn++] = a;
		}
		if (adj[b].color == 1){
			rs[rn++] = b;
		}
		a = adj[a].parent;
		b = adj[b].parent;
	}
	if (bn + rn < k)
		return -1;
	if (reverse == true){
		if (k <= rn)
			return rs[k-1];
		return bs[bn-(k-rn)];
	} else {
		if (k <= bn)
			return bs[k-1];
		return rs[rn-(k-bn)];
	}
}

void toggle(int x){
	adj[x].color = !adj[x].color;
}

void _updateTree(int n, int level){
	adj[n].level = level;
	for (pair<int,bool>e : adj[n].cs) {
		_updateTree(e.first,level+1);
	}
}
void changeParent(int u, int v){
	if (adj[u].parent == v)
		return ;
	adj[adj[u].parent].cs.erase(u);
	adj[u].parent = v;
	_updateTree(u, adj[v].level+1);
}

void	resolve(int n, int q){
	//parse tree
	int p,c;
	adj[1].level = 0;
	adj[1].parent = -1;
	for (int i = 1; i <= n; i+=1){
		cin >> c;
		adj[i].color = c;
	}
	for (int i = 2; i <= n; i+=1){
		cin >> p;
		adj[i].parent = p;
		adj[p].cs[i] = true;
		adj[i].level = adj[p].level + 1;
	}
	//answer queries
	char kind;
	int u,v,x,k;
	for (int _ = 0; _ < q; _ += 1){
		cin >> kind;
		if (kind == 'K'){
			cin >> u >> v >> k;
			cout << kthBlack(u,v,k) << "\n";
		}
		if (kind == 'T'){
			cin >> x;
			toggle(x);
		}
		if (kind == 'C'){
			cin >> u >> v;
			changeParent(u, v);
		}
	}
}

int main(){
	int n,q;

	cin >> n >> q;
	resolve(n, q);
}
