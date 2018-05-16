#include <bits/stdc++.h>

using namespace std;

void increase(int *a, int *count, int letter){
	if (a[letter] == 0)
		(*count) += 1;
	a[letter] += 1;
}
void decrease(int *a, int *count, int letter){
	a[letter] -= 1;
	if (a[letter] == 0)
		(*count) -= 1;
}

int sub(string & s, int block){
	int total = 0;
	int a[3] = {0,0,0};
	int count = 0;
	for (int i = 0; i < block; i++){
		increase((int*)a, &count, s[i]-'a');
	}
	for (int i = 0; i + block <= s.length(); i += 1){
		if (count < 3)
			total += 1;
		if (i > 0)
			decrease((int*)a, &count, s[i-1]-'a');
		if (i + block + 1 < s.length())
			increase((int*)a, &count, s[i+block+1]-'a');
	}
	return total;
}

int findSubstrings(string s){
	int total = 0;
	for (int i = 1; i <= s.length(); i+=1){
		total += sub(s, i);
	}
	return total;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		string s;
		cin >> s;
		cout << findSubstrings(s) << endl;
	}
}
