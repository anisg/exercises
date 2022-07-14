#include <bits/stdc++.h>

using namespace std;

pair<int,int> regularness(string & s){
	int n = (int)s.size();
	pair<int,int> p = {0,0};
	int a = 0;
	for (int i = 0; i < n; i += 1){
		if (s[i]=='(')
			a += 1;
		else
			a -= 1;
		p.first = min(p.first, a);
	}
	p.first *= -1;
	p.second = max(p.second, a);
	return p;
}

size_t resolve(vector<pair<int,int>> & v, int n,unordered_map<int,int> & m, int mo){
	size_t total = 0;
	for (int i = 0; i < n; i += 1){
		if (v[i].first == 0 && v[i].second == 0)
			total += mo;
		else if (v[i].first == 0 && m.count(v[i].second))
			total += m[v[i].second];
	}
	return total;
}

int main(){
	int n;
	vector<pair<int,int>> v;
	unordered_map<int,int> m;
	int mo = 0;

	//parsing
	cin >> n;
	for (int i = 0; i < n; i += 1){
		string s;
		cin >> s;
		//answer
		pair<int,int> p = regularness(s);
		if (p.first == 0 && p.second == 0){
			mo += 1;
		}
		else if (p.second == 0){
			if (m.count(p.first) == 0) m[p.first] = 1; else m[p.first] += 1;
		}
		v.push_back(p);
	}
	//find solution
	cout << resolve(v,n, m,mo) << "\n";
}
