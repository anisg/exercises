#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	int recval;
	vector<struct Node *> childs;
	vector<int> treeOr;
	vector<int> treeOrReverse;
	Node(int val) : val(val), recval(0), childs({}), treeOr({}), treeOrReverse({}) {}
};

int traverseCreate(Node & n, int father)
{
	vector<int> c;
	for (int i = 0; i < n.childs.size(); i += 1){

		int v = traverseCreate(*n.childs[i], father | n.val);
		n.recval |= v;
		c.push_back(v);
	}
	int cs = c.size();
	int v = 0;
	int vr = 0;
	n.treeOr.reserve(cs);
	n.treeOrReverse.reserve(cs);
	for (int i = 0; i < cs; i += 1) {
		n.treeOr[i] = v;
		v |= c[i];
		n.treeOrReverse[cs-1-i] = vr;
		vr |= c[cs-1-i];
	}
	n.recval |= n.val;
	return n.recval;
}

int traverseCount(Node & n, int v)
{
	int count = 0;
	if (v < 0)
		v = 0;
	else if (v == n.recval)
		count += 1;
	for (int i = 0; i < n.childs.size(); i += 1){
		count += traverseCount(*n.childs[i], (v | n.val | n.treeOr[i] | n.treeOrReverse[i]));
	}
	return count;
}

int main()
{
	int N;
	int ir = -1;
	vector<Node> nodes;
	//parsing
	cin >> N;
	for (size_t i = 0; i < N; i+=1)
	{
		int v;
		cin >> v;
		nodes.push_back(Node(v));
	}
	for (size_t i = 0; i < N - 1; i+=1)
	{
		int A,B;
		cin >> A >> B;
		if (ir < 0) ir = A-1;
		nodes[A-1].childs.push_back(&nodes[B-1]);
	}
	//precalculate... O(n)
	traverseCreate(nodes[ir], 0);
	//resolve... O(n)
	cout << traverseCount(nodes[ir], -1) << endl;
}
