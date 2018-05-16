#include <bits/stdc++.h>

using namespace std;

int resolve(unordered_map<int,bool> & map, int x)
{
	if (map.find(x) != map.end())
		return true;
	return false;
}

int main()
{
	int N,Q;
	cin >> N >> Q;
	unordered_map<int,bool> map;

	for (int i = 0; i < N; i += 1)
	{
		int j;
		cin >> j;
		map.insert(make_pair(j, true));
	}
	for (int i = 0; i < Q; i += 1){
		int x;
		cin >> x;
		cout << (resolve(map, x) == true ? "YES" : "NO") << endl;
	}
}
