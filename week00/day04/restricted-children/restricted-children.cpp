// Write your code here
#include <iostream>
#include <cmath>

using namespace std;

struct Node
{
	int countChilds;
	vector<Node> childs;
	Node(): childs() {}
	bool operator()(Node a, Node b) const
	{
		return a.countChilds < b.countChilds;
	}
};

Node orderTree(Node & n){
	for (size_t i = 0; i < n.childs.size(); i++){
		orderTree(n.childs[i]);
	}
	sort(n.childs.begin(), n.childs.end(), Node);
	return n;
}

Node buildTree(int n) {
	vector <struct Node> ns(n);
	for (int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		if (!ns[a])
			ns[a] = Node();
		if (!ns[b])
			ns[b] = Node();
		ns[a].push_back(ns[b]);
	}
	return ns[0];
}

int xspecifique(int x, Node & node){
	int total = 0;
	if (node.childs.size() <= x){
		for (int i = 0; i < x; i++){
			total += xspecifique(x, node.childs[i]);
		}
		for (int i = x; i < node.childs.size(); i++){
			total += 1 + node.childs[i].countChilds;
		}
		return total;
	} else {
		return node.countChilds;
	}
}

int main()
{
	int N;
	cin >> N;
	Node root = buildTree(N);
	orderTree(root);
	for (int x = 1; x <= N; x += 1)
		cout << xspecifique(x, root) << endl;
}
