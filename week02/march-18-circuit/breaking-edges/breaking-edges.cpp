#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	int desc;
	int asc;
	vector<struct Node *> childs;
	vector<int> treeOr;
	vector<int> treeOrReverse;
	Node(int val) : val(val), desc(0), asc(0), childs({}), treeOr({}), treeOrReverse({}) {}
};

int traverseCreate(Node & n, int father)
{
	vector<int> c;
	n.asc = father;
	for (int i = 0; i < n.childs.size(); i += 1){
		int v = traverseCreate(*n.childs[i], father | n.val);
		n.desc += v;
		c.push_back(v);
	}
	int v = 0;
	int vr = 0;
	for (int i = 0; i < c.size(); i += 1) {
		n.treeOr.push_back(v);
		n.treeOrReverse.push_back(vr);
		v |= c[i];
		vr |= c[c.size()-1-i];
	}
	cout << "-->" << n.val << endl;
	for (int i = 0; i < c.size(); i += 1){
		cout << n.treeOr[i] << "++" << n.treeOrReverse[i] << endl;
	}
	n.desc |= n.val;
	return n.desc;
}

int traverseCount(Node & n)
{
	int count = 0;
	for (int i = 0; i < n.childs.size(); i += 1){
		if (n.childs[i]->desc == (n.asc | n.desc | n.treeOr[i] | n.treeOrReverse[i]))
			count += 1;
		count += traverseCount(*n.childs[i]);
	}
	return count;
}

int main()
{
	int N;
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
		nodes[A].childs.push_back(&nodes[B]);
	}
	//precalculate... O(n)
	traverseCreate(nodes[0], 0);
	//resolve... O(n)
	cout << traverseCount(nodes[0]) << endl;
}
