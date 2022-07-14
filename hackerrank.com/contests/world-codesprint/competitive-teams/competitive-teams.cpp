#include <bits/stdc++.h>

using namespace std;

float     fact(long a){
	return tgamma(a+1);
}

long comb(int n, int r){
	if (r > n) return 0;
	return (fact(n)/(fact(r)*(fact(n-r))));
}

struct Set {
	unordered_map<int,int> pos;
	vector<vector<int>> v;
	int c[100000+1];
	int			mc;
	long		t;
	long x[100000+1];

	Set(int n){
		//take n into account...
		c[0] = 0;
		x[0] = -1;
		c[1] = n;
		x[1] = 0;
		mc = 1;
		t = 0;
	}

	void createSubSet(int x) {
		v.push_back({x});
		pos[x] = v.size()-1;
	}

	void calculCompet(){
		t = 0;
		long l = 0;
		x[0] = -1;
		for (int step = 1; step <= mc-1; step += 1){
			x[step] = 0;
			for (int i = 0; i + step <= mc; i += 1){
				x[step] += ((long)c[i]) * ((long)c[i + step]);
			}
			t += x[step];
		}
		l = t;
		for (int step = mc-1; step >= 1; step -= 1){
			l -= x[step];
			x[step] = t-l;
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

	int competitiveness(int cn) {
		if (cn >= mc)
			return 0;
		if (cn == 0 && x[cn] == -1){
			//calculate
			x[cn] = 0;
			for (int i = 1; i <= mc; i += 1){
				x[cn] += comb(c[i], 2);
			}
			x[cn] += t;
		}
		return x[cn];
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
