#include <bits/stdc++.h>

using namespace std;

struct Node{
	vector<int> childs;
	unordered_map<int, bool> mr;
	int grp;
	int parent;
	int level;
	bool haveChild(int y){return mr.count(y) > 0;}
};

int gsize[200000+1];
int lim=1;
Node adj[200000+1];
unordered_map<size_t,int> mem;

void updateGrp(int father, int c, int ng){
	gsize[adj[c].grp] -= 1;
	adj[c].grp = ng;
	gsize[ng] += 1;
	int len = adj[c].childs.size();
	for (int i = 0; i < len; i += 1)
		if (adj[c].childs[i] != father && adj[c].mr[adj[c].childs[i]] == false)
			updateGrp(c, adj[c].childs[i], ng);
}

int dist(int a, int b){
	int d = 0;
	if (adj[a].level < adj[b].level)
		swap(a,b);
	while (adj[a].level != adj[b].level){
		a = adj[a].parent;
		d++;
	}
	while (a != b){
		a = adj[a].parent;
		b = adj[b].parent;
		d += 2;
	}
	return d;
}

void _init(int c, int parent, int level)
{
	adj[c].level = level;
	adj[c].parent = parent;
	gsize[0] += 1;
	int j;
	int len = adj[c].childs.size();
	for (int i = 0; i < len; i += 1){
		j = adj[c].childs[i];
		if (j != parent)
			_init(j, c, level+1);
	}
}

void init(int root){
	gsize[0] = 0;
	lim = 1;
	_init(root, -1, 0);
}

bool closeRoad(int x, int y){
	if (!adj[x].haveChild(y))
		return false;
	if (adj[x].mr[y] == true)
		return true;
	adj[x].mr[y] = true;
	adj[y].mr[x] = true;
	gsize[lim++] = 0;
	updateGrp(x, y, lim-1);
	return true;
}

bool openRoad(int x, int y){
	if (!adj[x].haveChild(y))
		return false;
	if (adj[x].mr[y] == false)
		return true;
	adj[x].mr[y] = false;
	adj[y].mr[x] = false;
	updateGrp(x, y, adj[x].grp);
	return true;
}

size_t hsh(int x, int y){
	size_t h = 0;
	h = (((size_t)x) << 32) | (size_t)y;
	return h;
}

bool query(int x, int y){
	if (adj[x].grp != adj[y].grp)
		return false;
	size_t h = hsh(min(x,y),max(x,y));
	if (!mem.count(h))
		mem[h] = dist(x,y);
	cout << mem[h] << "\n";
	return true;
}

void landslide(int n){
	char k;
	int x,y;
	int j = -1;
	//get graph
	for (int i = 0; i < n-1; i += 1){
		cin >> x >> y;
		if (j<0)j=x;
		adj[x].childs.push_back(y);
		adj[x].mr[y] = false;
		adj[x].grp = 0;
		adj[y].childs.push_back(x);
		adj[y].mr[x] = false;
		adj[y].grp = 0;
	}
	if (j != -1)
		init(j);
	else
		gsize[0]=1;
	int q;
	//get queries
	cin >> q;
	for (int _ = 0; _ < q; _ += 1){
		cin >> k >> x >> y;
		if (k == 'd')
			closeRoad(x, y);
		if (k == 'c')
			openRoad(x, y);
		if (k == 'q'){
			if (!query(x,y))
				cout << "Impossible\n";
		}
	}
}

int main(){
	int n;

	cin >> n;
	landslide(n);
}
