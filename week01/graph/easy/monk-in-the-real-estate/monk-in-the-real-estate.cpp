#include <bits/stdc++.h>

using namespace std;

int getCities(int E)
{
	unordered_map<int, bool> map;
	for (int e = 0; e < E; e += 1){
		int x,y;
		cin >> x >> y;
		if (map.find(x) == map.end())
			map.insert({x,true});
		if (map.find(y) == map.end())
			map.insert({y,true});

	}
	return map.size();
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t += 1){
		int E; //number of roads
		cin >> E;
		cout << getCities(E) << endl;
	}
}
