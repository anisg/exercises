#include <bits/stdc++.h>

using namespace std;

void findTheAbsentStudents(int n, vector<int> &a){
	int *here = new int[n+1]();
	for (int i = 0; i < a.size(); i += 1){
		here[a[i]] = true;
	}
	string s;
	for (int i = 1; i <= n; i += 1){
		if (!here[i])
			s += (s.empty() ? "" : " ") + to_string(i);
	}
	cout << s << '\n';
}

int main(){
	int N;
	vector<int> a;

	cin >> N;
	for (int i = 0; i < N; i += 1){
		int p;
		cin >> p;
		a.push_back(p);
	}
	findTheAbsentStudents(N, a);
}
