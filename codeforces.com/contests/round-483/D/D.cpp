#include <bits/stdc++.h>

using namespace std;

int v[200000+1];

bool abc(int a, int b, int c){
	cout << "3\n";
	cout << a << " " << b << " " << c << "\n";
	return true;
}

bool ab(int a, int b){
	cout << "2\n";
	cout << a << " " << b << "\n";
	return true;
}

bool resolve(int *v, int n){
	pair<int,int> p = {INT_MIN,INT_MIN};
	unordered_map<int,bool> m;
	for (int i = 0; i < n; i+=1){
		m[v[i]] = true;
	}
	for (int i = 0; i < n; i+=1){
		long long n = 1;
		for (int x = 0; x < 31; x++){
			if (v[i] - n < INT_MIN)
				break ;
			if (m.count(v[i]-n)){
				if (p.first == INT_MIN)
					p = {v[i],v[i]-n};
				if (v[i]+n < INT_MAX && m.count(v[i]+n))
					return abc(v[i]-n,v[i],v[i]+n);
			}
			n *= 2;
		}
	}
	if (p.first != INT_MIN){
		return ab(p.first, p.second);
	} else {
		cout << "1\n";
		cout << v[0] << "\n";
		return true;
	}
}

int main(){
	int n;

	//parsing
	cin >> n;
	for (int i = 0; i < n; i += 1){
		int a;
		cin >> a;
		v[i] = a;
	}
	//solution
	resolve(v,n);
}
