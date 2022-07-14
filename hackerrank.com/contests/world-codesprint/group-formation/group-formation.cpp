#include <bits/stdc++.h>

using namespace std;

int A,B,F,S,T;

struct GroupInfo {
	int c,g[3];
	bool canMerge(GroupInfo & other){
		if (this->c + other.c > B
		|| this->g[0] + other.g[0] > F
		|| this->g[1] + other.g[1] > S
		|| this->g[2] + other.g[2] > T)
			return false;
		return true;
	}
	void merge(GroupInfo & other){
		this->c += other.c;
		this->g[0] += other.g[0];
		this->g[1] += other.g[1];
		this->g[2] += other.g[2];
	}
	bool isValid() {
		if (this->c >= A && this->c <= B) return true;
		return false;
	}
};

struct JoinSet {
	GroupInfo info;
	vector<string*> items;
	bool canJoin(JoinSet & set){
		if (this->info.canMerge(set.info)) return true;
		return false;
	}
	void join(JoinSet & set){
		for (int i = 0; i < set.items.size(); i += 1){
			this->items.push_back(set.items[i]);
		}
		this->info.merge(set.info);
	}
	JoinSet(string *s, int grad){
		this->info = {1, {0,0,0}};
		this->info.g[grad] = 1;
		this->items.push_back(s);
	}
	bool isValid(){return this->info.isValid();}
	int size(){return this->info.c;}
};

void printGroups(vector<JoinSet*> & b){
	vector<string> v;
	for (int x = 0; x < b.size(); x += 1){
		JoinSet *g = b[x];
		for (int i = 0; i < g->items.size(); i += 1){
			v.push_back(*(g->items[i]));
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i += 1){
		cout << v[i] << '\n';
	}
}

void updateOrder(JoinSet & s, unordered_map<string,int> & order, int x){
	for (int i = 0; i < s.items.size(); i += 1){
		order[*s.items[i]] = x;
	}
}

JoinSet &findGroup(vector<JoinSet> & groups, unordered_map<string,int> & order, string & s){
	return groups[order[s]];
}

void resolve(vector<JoinSet> & groups, unordered_map<string,int> & order, int m){
	vector<JoinSet*> b;
	unordered_map<int,bool> ids;
	int size = INT_MIN;

	string s1,s2;
	//perform queries
	for (int _= 0; _< m; _+= 1){
		cin >> s1 >> s2;
		int i = order[s1];
		JoinSet & g1 = findGroup(groups, order, s1);
		JoinSet & g2 = findGroup(groups, order, s2);
		if (&g1 == &g2)
		 continue ;
		if (g1.canJoin(g2)){
			updateOrder(g2, order, order[s1]);
			g1.join(g2);
		}
		if (g1.isValid() && ids.count(i) == 0){
			if (!b.size() || g1.size() > size){
				size = g1.size();
				b = {&g1};
				ids = {};
				ids[i] = true;
			}
			else if (g1.size() == size){
				b.push_back(&g1);
				ids[i] = true;
			}
		}
	}
	if (!b.size())
		cout << "no groups" << '\n';
	else {
		printGroups(b);
	}
}

int main(){
	int n,m;

	cin >> n >> m >> A >> B >> F >> S >> T;
	unordered_map<string,int> studs;
	vector<JoinSet> groups;
	for (int i = 0; i < n; i += 1){
		string *s = new string("");
		int grad;
		cin >> (*s) >> grad;
		groups.push_back(JoinSet(s,grad-1));
		studs[*s] = i;
	}
	resolve(groups, studs, m);
}
