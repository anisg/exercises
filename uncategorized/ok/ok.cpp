#include <bits/stdc++.h>

using namespace std;

int bget(int n, int i)
{
	return ((1 << i) & n) != 0;
}

int getVeryCoolness(int n, int K)
{
	int count = 0;
	for (int i = 0; i < 29; i+= 1)
	{
		count += (bget(n, i) == 1 && bget(n, i+1) == 0 && bget(n, i+2) == 1);
	}
	return count >= K;
}

int resolve(int R, int K)
{
	int count = 0;
	for (int i = 1; i <= R; i += 1)
	{
		count += getVeryCoolness(i, K);
	}
	return count;
}

int main()
{
	int T;
	cin >> T;
	for (int _ = 0; _ < T; _ += 1){
		//resolve here
		int R,K;
		cin >> R >> K;
		cout << resolve(R, K) << endl;
	}
}
