#include <bits/stdc++.h>

using namespace std;

stack<int> findPath(vector<int> *nodes, int a, int b)
{
	unordered_map<int,int> v;
	queue<pair<int,int> > q;
	int x,father;

	q.push( make_pair(a, -1) );
	while (!q.empty())
	{
		tie(x,father) = q.front();
		q.pop();
		v.insert({x, father});
		if (x == b)
			break;
		for (int i = 0; i < nodes[x].size(); i+=1){
			if (v.find(nodes[x][i]) == v.end()){
				q.push( make_pair(nodes[x][i], x) );
			}
		}
	}
	stack<int> res;
	if (x == b){
		while (x != -1)
		{
			res.push(x);
			x = v.find(x)->second;
		}
	}
	return res;
}

int main()
{
	int N,M,C,T;
	cin >> N >> M >> C >> T;
	vector<int> *nodes = new vector<int>[N+1]();
	//build graph
	for (int i = 0; i < M; i+=1){
		int a,b;
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	int X,Y;
	cin >> X >> Y;

	//find solution
	stack<int> res = findPath(nodes, X, Y);

	cout << res.size() << endl;
	while (!res.empty())
	{
		cout << res.top();
		res.pop();
		if (!res.empty())
			cout << " ";
	}
	cout << endl;
}
