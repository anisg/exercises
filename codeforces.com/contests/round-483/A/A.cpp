#include <bits/stdc++.h>

using namespace std;

void resolve(vector<int> & v, int n, int k){
	unordered_map<int,int> m;

	for (int i = 0; i < n; i += 1){
		if (m.count(v[i]) == 0)
			m[v[i]] = i+1;
	}
	if (m.size() >= (size_t)k){
		cout << "YES" << "\n";
		auto it = m.begin();
		for (int i = 0; i < k; i++){
			cout << it->second;
			if (i + 1 < k)
				cout << " ";
			it++;
		}
	} else {
		cout << "NO" << "\n";
	}


}

int main(){
	int n,k;
	vector<int> v;

	cin >> n >> k;
	for (int _ = 0; _ < n; _ += 1){
		int a;
		cin >> a;
		v.push_back(a);
	}
	resolve(v,n,k);
}
