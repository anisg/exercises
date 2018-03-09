#include <bits/stdc++.h>

using namespace std;

void maximizeDigit(string &s, int count){
	for (int i = 0; i < s.length(); i+=1){
		if (count == 0)
			break;
		if (s[i]-'0' < 9){
			s[i] = '9';
			count -= 1;
		}
	}
}

int main()
{
	string Xs;
	int K;
	cin >> Xs >> K;
	maximizeDigit(Xs, K);
	cout << stol(Xs) << endl;
}
