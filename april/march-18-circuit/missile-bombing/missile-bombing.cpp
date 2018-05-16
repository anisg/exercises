#include <bits/stdc++.h>

using namespace std;

void bombIt(int *m, int N, int y, int x, int p)
{
	m[y*N + x] ^= p;
}

void bomb(int *m, int N, int p, int a, int b, int c, int d)
{
	for (int y = a; y <= c; y += 1)
	{
		for (int x = b; x <= d; x += 1)
		{
			bombIt(m, N, y, x, p);
		}
	}
}

int main()
{
	//parsing
	int N, M, p,a,b,c,d;
	cin >> N;
	int *m = new int[N*N]();
	cin >> M;
	for (int i = 0; i < M; i += 1){
		cin >> p >> a >> b >> c >> d;
		bomb(m, N, p, a-1, b-1, c-1, d-1);
	}
	//result
	for (int y = 0; y < N; y += 1){
		for (int x = 0; x < N; x += 1){
			cout << m[y*N + x] << ((x + 1 >= N) ? "" : " ");
		}
		cout << endl;
	}
}
