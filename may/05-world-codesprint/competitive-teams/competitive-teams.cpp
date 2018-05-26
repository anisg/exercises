#include <bits/stdc++.h>

using namespace std;

struct Set {
	unordered_map<int,int> pos;
	vector<vector<int>> v;
	vector<int> sums;
	int			m;
	createSubSet(int x){
		v.push_back({x});
		sums[1] += 1;
		pos[x] = v.size()-1;
	}
	mergeSubSets(int p1, int p2){
		int s1 = v[p1].size();
		int s2 = v[p2].size();
		int ns = s1 + s2;
		for (int i = s1; i <= ns; i +=1)
			sums[i] -= 1;
		for (int i = s2; i <= ns; i +=1)
			sums[i] -= 1;
		sums[ns] += 1;
		v[p1]
	}
	void join(int x, int y){
		if (pos.count(x) == 0){createSubSet(x);}
		if (pos.count(y) == 0){createSubSet(y);}
		mergeSubSets(pos[x], pos[y]);
	}
};

int answerQueries(int n, int q){
	Set set;
	for (int _ = 0; _ < q; _ += 1){
		int k;
		cin >> k;
		if (k == 2){
			int c;
			cin >> c;
		} else {
			int x,y;
			cin >> x >> y;
			set.join(x,y);
		}
	}
}

int main(){
	int n,q;

	cin >> n >> q;
	answerQueries(n,q);
}
