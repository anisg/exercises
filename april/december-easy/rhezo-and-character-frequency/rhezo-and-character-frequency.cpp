#include <bits/stdc++.h>

using namespace std;

int getMaxFreq(string s, char c, int p){
	int count = 0;
	int maxFreq = 0;
	for (int i = 0; i < s.length(); i+=1){
		if ((i - p >= 0) && (s[i - p] == c))
			count -= 1;
		if (s[i] == c)
			count += 1;
		maxFreq = max(maxFreq, count);
	}
	return maxFreq;
}

int findMaxFrequencyInterval(string s, char c, int p)
{
	int reach = getMaxFreq(s, c, p) + 1;
	int count = 0;
	int result = 1;
	for (int i = 0; i < s.length(); i += 1){
		if ((i - p >= 0) && (s[i - p] == c))
			count -= 1;
		if (s[i] == c)
			count += 1;
		if (count + 1 == reach){
			result = i;
		}
	}
	return result;
}

int main()
{
	string S;
	char C;
	int P;
	cin >> S;
	cin >> C;
	cin >> P;

	cout << findMaxFrequencyInterval(S,C,P) << endl;
}
