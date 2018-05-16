#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int _ = 0; _ < T; _ += 1){
		//resolve here
		int a,H,THETA;
		cin >> a >> H >> THETA;
		int maxn;
		for (int i =THETA; i >= 1; i -= 1)
		{
			printf("%dm %d v %d\n", THETA, (H*a), H*cos(i));
		}
	}
	cout << T << endl;
}
