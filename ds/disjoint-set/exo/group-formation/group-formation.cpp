#include <bits/stdc++.h>

using namespace std;

/* ---------------------------------------- */
/* -------------     Debug       ---------- */

//operator '<<' on vector
template <typename T>
ostream& operator<<(ostream& os, vector<T> & v) {
	os << "[";
	for (size_t i = 0; i < v.size(); i += 1){
		os << v[i];
		if (i + 1 < v.size())
			os << ", ";
	}
	os << "]";
	return os;
}

//parenthesis on
template <typename T>
ostream parenthesis(T a){
	ostream os;
	os << "(" << a << ")";
	return os;
}

/* ---------------------------------------- */
/* ------------- Data structure  ---------- */

// UnionFind : --join a b, --set a, --find a
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

int A,B,F,S,T;
unordered_map<string,int> mp;

struct Group {
	int c,g[3];
	vector<string> names;
	bool canMerge(Group & b){
		return !(c + b.c > B
			|| g[0] + b.g[0] > F
			|| g[1] + b.g[1] > S
			|| g[2] + b.g[2] > T);
	}
	bool isValid() { return (this->c >= A && this->c <= B); }
	Group & operator+=(Group & b){
		for (int i = 0; i < b.names.size(); i += 1){ names.push_back(b.names[i]); }
		c += b.c;
		g[0] += b.g[0];
		g[1] += b.g[1];
		g[2] += b.g[2];
		return *this;
	}
};

void printGroups(vector<Group*> & v) {
	vector<string> names;
	for (int x = 0; x < v.size(); x += 1){
		Group *g = v[x];
		for (int i = 0; i < g->names.size(); i += 1){
			names.push_back(g->names[i]);
		}
	}
	sort(names.begin(), names.end());
	for (int i = 0; i < names.size(); i += 1){
		cout << names[i] << '\n';
	}
}

Group init(int i) {
	string name;
	int grad;
	cin >> name >> grad;
	Group group({ 1, {0,0,0}, {} });
	group.g[grad-1] += 1;
	group.names.push_back(name);
	mp[name] = i;
	return group;
}

void resolve(int n, int m) {
	UnionFind<Group> u(n, &init);
	vector<Group*> valids;
	unordered_map<int,bool> ids;
	for (int i= 0;i<n;i++){
		cout << u.sets[i].names;
	}
	int maxi = 0;
	//Queries
	for (int _= 0; _< m; _+= 1){
		string s1,s2;
		cin >> s1 >> s2;
		int a = u.find(mp[s1]);
		int b = u.find(mp[s2]);
		if (a == b)
			continue ;
		cout << s1  << parenthesis(u.sets[a].names) << " v " << s2  << parenthesis(u.sets[b].names) << "\n";
		if (u.set(a).canMerge(u.set(b))){
			cout << "merge" << endl;
			u.join(a,b);
		}
		cout << u.sets[a].names << endl;
		if (u.set(a).isValid()) {
			if  (valids.size() == 0 || (u.set(a).c > maxi)){
				valids = {&u.set(a)};
			}
			else if (u.set(a).c == maxi)
				valids.push_back(&u.set(a));
			maxi = valids[0]->c;
		}
	}
	//Result
	if (!valids.size())
		cout << "no groups" << '\n';
	else {
		printGroups(valids);
	}
}
int main(){
	int T;
	int n,m;

	cin >> n >> m >> A >> B >> F >> S >> T;
	resolve(n, m);
}
