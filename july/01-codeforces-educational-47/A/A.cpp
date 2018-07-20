#include <bits/stdc++.h>

using namespace std;

int resolve(vector<int> & c, int cn, vector<int> & a, int an){
	int x = 0;
	for (int i = 0; i < cn; i += 1){
		if (x >= an)
			break ;
		if (a[x] >= c[i])
			x += 1;
	}
	return x;
}

int main(){
	int cn;
	vector<int> c;
	int an;
	vector<int> a;

	//parsing
	cin >> cn >> an;
	int x;
	for (int i = 0; i < cn; i += 1){
		cin >> x;
		c.push_back(x);
	}
	for (int i = 0; i < an; i += 1){
		cin >> x;
		a.push_back(x);
	}
	//find solution
	cout << resolve(c, cn,  a, an) << "\n";
}
