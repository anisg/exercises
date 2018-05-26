#include <bits/stdc++.h>

using namespace std;

struct Node{
	vector<int> childs;
	unordered_map<int, bool> mr;
	int grp;
	bool haveChild(int y){return mr.count(y) > 0;}
};

Node adj[200000+1];
unordered_map<size_t,int> mem;

size_t hsh(int x, int y){
	unsigned int a = min(x,y);
	unsigned int b = max(x,y);
	size_t h = 0;
	h = (((size_t)a) << 32) | b;
	return h;
}

void updateGrp(int father, int c, int ng){
	adj[c].grp = ng;
	for (int i = 0; i < adj[c].childs.size(); i += 1)
		if (adj[c].childs[i] != father && adj[c].mr[adj[c].childs[i]] == false)
			updateGrp(c, adj[c].childs[i], ng);
}

int _dist(int father, int c, int y, int s, int from){
	int r = 0;
	mem[hsh(from, c)] = s;
	if (c == y)
		return s;
	for (int i = 0; i < adj[c].childs.size(); i += 1){
		if (adj[c].childs[i] != father && adj[c].mr[adj[c].childs[i]] == false)
			if ((r = _dist(c, adj[c].childs[i], y, s + 1, from)) > 0)
				break ;
	}
	return r;
}
int dist(int c, int y){
	if (c == y)
		return 0;
	return _dist(-1, c, y, 0, c);
}

bool closeRoad(int x, int y){
	if (!adj[x].haveChild(y))
		return false;
	if (adj[x].mr[y] == true)
		return true;
	adj[x].mr[y] = true;
	adj[y].mr[x] = true;
	updateGrp(x, y, adj[x].grp + 1);
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

bool query(int x, int y){
	if (adj[x].grp != adj[y].grp)
		return false;
	size_t h = hsh(x,y);
	int c;
	if (!mem.count(h))
		c = dist(x,y);
	cout << c << "\n";
	return true;
}

void landslide(int n){
	char k;
	int x,y;
	//get graph
	for (int i = 0; i < n-1; i += 1){
		cin >> x >> y;
		adj[x].childs.push_back(y);
		adj[x].mr[y] = false;
		adj[x].grp = 0;
		adj[y].childs.push_back(x);
		adj[y].mr[x] = false;
		adj[y].grp = 0;
	}
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
