#include <bits/stdc++.h>

using namespace std;

#define M 1000

void sendPos(int r, int y, int x)
{
	cout << r + y << " " << r + x << endl;
}

pair<int,int> getRectDim(int A)
{
	pair<int,int> p;

	p.first = 3;
	while (A % p.first != 0) A += 1;
	p.second = A / p.first;
	return p;
}

void getAnchors(int h, int w, vector<pair<int,int>> & anchors)
{
	int y = 1;
	while (y < h)
	{
		int x = 1;
		while (x < w)
		{
			anchors.push_back(make_pair(y,x));
			x += 3;
			if (x == w) x -= 2;
			else if (x == w-1) x -= 1;
		}
		y += 3;
		if (y == h) y -= 2;
		else if (y == h-1) y -= 1;
	}
}

bool validbatch(pair<int,int> & anchor, char **m)
{
	int y,x;
	tie(y,x) = anchor;
	if (m[y][x] &&
		m[y][x-1] && m[y][x+1] &&
		m[y-1][x] && m[y+1][x] &&
		m[y-1][x-1] && m[y-1][x+1] &&
		m[y+1][x-1] && m[y+1][x+1]
		)
		return true;
	return false;
}

bool getGopherDeploy(int r, char **m)
{
	int y,x;

	cin >> y >> x;
	if (y <= 0 || x <= 0)
		return false;
	m[y-r][x-r] = 1;
	return true;
}

void trysolve(int A)
{
	int h,w;
	tie(h,w) = getRectDim(A);
	char **m = new char*[h];for(int i = 0; i < h; i += 1) { m[i] = new char[w](); }
	int r = M/4;
	vector<pair<int,int>> anchors;
	getAnchors(h,w, anchors);

	size_t i = 0;
	while (i < anchors.size())
	{
		if (!validbatch(anchors[i], m))
		{
			sendPos(r, anchors[i].first, anchors[i].second);
			if (!getGopherDeploy(r, m))
				return ;
		}
		else
			i += 1;
	}
}

int main()
{
	int T;
	int A;

	cin >> T;
	for (int t = 0; t < T; t += 1)
	{
		cin >> A;
		trysolve(A);
	}
}
