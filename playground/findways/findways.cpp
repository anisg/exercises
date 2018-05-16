#include <bits/stdc++.h>

using namespace std;

void explore(vector<vector<char>> & m, int x, int y, int & c)
{
    int n = (int)m.size();

    if (x < 0 || y < 0 || x >= n || y >= n || m[y][x] == 1)
        return ;
    if (x == n - 1 && y == n - 1){
        c += 1;
        return ;
    }
    char tmp = m[y][x];

    m[y][x] = 1;
    explore(m, x+1, y, c);
    explore(m, x, y+1, c);
    explore(m, x-1, y, c);
    explore(m, x, y-1, c);
    m[y][x] = tmp;
}

int find_possible_ways(vector<vector<char>> & m)
{
    int c = 0;
    explore(m, 0, 0, c);
	return c;
}

int main()
{
	int N;
	vector<vector<char>> m;

	cin >> N;

	for (int l = 0; l < N; l += 1){
	    vector<char> tmp;
		for (int c = 0; c < N; c += 1){
		    int nb;
		    cin >> nb;
		    tmp.push_back(nb);
		}
		m.push_back(tmp);
	}
	cout << find_possible_ways(m) << endl;
}
