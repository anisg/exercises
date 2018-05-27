#include <bits/stdc++.h>

using namespace std;

int resolve(string & e, int & n){
	stack<char> s;
	int p[127];
	p['('] = 0;p[')'] = 0;
	for (int i = 0; i < n; i += 1){
		if (s.empty() || !(e[i] == ')' && s.top() == '(')){
			p[e[i]] += 1;
			s.push(e[i]);
		}
		else {
			p[s.top()] -= 1;
			s.pop();
		}
	}
	if (p['('] >= 1 && p[')'] >= 1) return 2;
	if (p['('] >= 1 || p[')'] >= 1) return 1;
	return 0;
}

int main(){
	string s;
	int n;

	cin >> n;
	cin >> s;
	cout << resolve(s,n) << "\n";
}
