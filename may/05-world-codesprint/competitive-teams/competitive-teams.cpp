#include <bits/stdc++.h>

using namespace std;

struct Set {
	unordered_map<int,int> pos;
	vector<vector<int>> v;
	int c[100000+1];
	int			mc;
	int x[100000+1];

	Set(int n){
		//take n into account...
		c[0] = 0;
		x[0] = 0;
		c[1] = n;
		x[1] = 0;
		mc = 1;
	}

	void createSubSet(int x) {
		v.push_back({x});
		pos[x] = v.size()-1;
	}

	void calculCompet(){
		size_t t = 0;
		size_t l = 0;
		for (int step = 1; step <= mc-1; step += 1){
			//cout << "c["<< step <<"] =" << c[step] << "\n";
			x[step] = 0;
			for (int i = 0; i + step <= mc; i += 1){
				x[step] += c[i] * c[i + step];
			}
			//cout << "px["<< step <<"] =" << x[step] << "\n";
			t += x[step];
		}
		//cout << "total =" << t << "\n";
		l = t;
		for (int step = mc-1; step >= 1; step -= 1){
			l -= x[step];
			x[step] = t-l;
			//cout << "  dx["<< step <<"] =" << x[step] << "\n";
		}
	}

	void mergeSubSets(int p1, int p2){
		int s1 = v[p1].size();
		int s2 = v[p2].size();
		int ns = s1 + s2;
		if (ns > mc){
			while (++mc <= ns){
				x[mc] = 0;
				c[mc] = 0;
			}
			mc = ns;
		}
		c[s1] -= 1;
		c[s2] -= 1;
		c[ns] += 1;
		for (int i = v[p2].size()-1; i >= 0; i -= 1){
			pos[v[p2][i]] = p1;
			v[p1].push_back(v[p2][i]);
			v[p2].pop_back();
		}
	}

	void join(int x, int y){
		int p1,p2;
		if (pos.count(x) == 0){createSubSet(x);}
		if (pos.count(y) == 0){createSubSet(y);}
		p1 = pos[x]; p2 = pos[y];
		if (p1 == p2)
			return ;
		if (v[p1].size() < v[p2].size())
			swap(p1, p2);
		mergeSubSets(p1, p2);
		calculCompet();
	}

	int competitiveness(int c) {
		if (c >= mc)
			return 0;
		if (c == 0){
			return -10;
		}
		return x[c];
	}
};

void answerQueries(int n, int q){
	Set set(n);
	for (int _ = 0; _ < q; _ += 1){
		int k;
		cin >> k;
		if (k == 2){
			int c;
			cin >> c;
			cout << set.competitiveness(c) << "\n";
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
