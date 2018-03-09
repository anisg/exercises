#include <bits/stdc++.h>

using namespace std;

bool isEven(int x){
	return (x == 1 || (x % 2 == 0));
}

int getWinner(int n, int x)
{
	int winner = 0;
	if (n <= 2)	return winner;

	while (x > 0){
		if (isEven(x))
			x = x / 2;
		else
			x = (x + 1) / 2;
		winner = !winner;
	}
	return (isEven(n) ? !winner : winner);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t += 1){
		int N,X;
		cin >> N >> X;
		cout << (getWinner(N, X) == 0 ? "Mojo" : "Jojo") << endl;
	}
}
