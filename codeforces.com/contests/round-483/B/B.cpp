#include <bits/stdc++.h>

using namespace std;

bool iter(vector<string> & v, int n, int x){
	if (x + 1 >= n)
		return true;
	if (v[x+1].find(v[x]) == string::npos)
		return false;
	return iter(v,n,x+1);
}

bool cmp(string & a, string & b){ return a.size() < b.size(); }

void resolve(vector<string> & v, int n){
	sort(v.begin(), v.end(), &cmp);
	if (iter(v,n,0)){
		cout << "YES" << "\n";
		for (int i = 0; i < n; i++){
			cout << v[i] << "\n";
		}
	} else {
		cout << "NO" << "\n";
	}
}

int main(){
	int n;
	vector<string> v;

	cin >> n;
	for (int _ = 0; _ < n; _ += 1){
		string s;
		cin >> s;
		v.push_back(s);
	}
	resolve(v,n);
}
