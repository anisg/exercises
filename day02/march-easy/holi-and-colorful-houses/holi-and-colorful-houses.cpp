// Write your code here
#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

int calcuNormal(string s, int x, int y){
	int i = x;
	int m = 0;
	while (i != y){
		if (s[i] != s[i + 1])
			m += 1;
		i += 1;
	}
	return m;
}
int calcuReverse(string s, int x, int y){
	int i = x;
	char next;
	int m = 0;
	while (i != y){
		next = (i == 0) ? s[s.length()-1] : s[i-1];
		if (s[i] != next)
			m += 1;
		if (i == 0){
			i = s.length()-1;
		} else {
			i -= 1;
		}
	}
	return m;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		int N,Q;
		cin >> N >> Q;
		string s;
		cin >> s;
		for (int i = 0 ; i < Q; i++){
			int x,y, xt,yt;

			cin >> xt >> yt;
			x = min(xt, yt)-1;
			y = max(xt, yt)-1;
			int m = INT_MAX;
			m = min(min(m, calcuNormal(s,x,y)), calcuReverse(s,x,y));
			cout << m << endl;
		}
	}
}
