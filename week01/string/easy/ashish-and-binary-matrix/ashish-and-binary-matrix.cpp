#include <bits/stdc++.h>

using namespace std;


bool haveUniqueRow(vector<string> vs, int n, int m)
{
	bool unique = false;
	for (int x = 0; x < m; x+=1){
		for (y = 0; y < n; y += 1){
			
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		int n,m;
		cin >> n >> m;
		vector<string> vs(n);
		for (int y = 0; y < n; y+=1)
			cin >> vs[y];
		cout << (haveUniqueRow(vs) == true) ? "Yes" : "No" << endl;
	}
	cout << T << endl;
}
