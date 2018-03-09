#include <bits/stdc++.h>

using namespace std;

bool isTree(int N, vector<int> degrees)
{
	int count = 0;
	for (int i = 0; i < N; i+=1){
		count += degrees[i];
	}
	return (count - N >= N) ? false : true;
}

int main()
{
	int N;
	cin >> N;
	vector<int> degrees;
	for (int i = 0; i < N; i += 1){
		int v;
		cin >> v;
		degrees.push_back(v);
	}
	cout << ((isTree(N, degrees) == true) ? "Yes" : "No") << endl;
}
