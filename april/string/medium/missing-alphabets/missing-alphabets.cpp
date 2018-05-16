#include <bits/stdc++.h>

using namespace std;

void printInOrder(vector<int> & a, vector<string> ws, int pos)
{
	vector<string> *vals = new vector<string>[ a.size() ]();

	for (size_t i = 0; i < ws.size(); i++){
		if (ws[i].length() > pos)
			vals[ a[ws[i][pos] - 'a'] ].push_back(ws[i]);
		else
			cout << ws[i] << endl;
	}
	for (size_t i = 0; i < a.size(); i++){
		if (vals[i].size() > 1)
			printInOrder(a, vals[i], pos + 1);
		else if (vals[i].size() == 1)
			cout << vals[i][0] << endl;
	}
}

int main() {
	int T;

	//parsing
	cin >> T;
	for (int t = 0; t < T; t++){
		string alphabet;
		int M;
		vector<string> words;

		cin >> alphabet;
		vector<int> a(26);
		for (size_t i = 0; i < alphabet.length(); i++)
			a[alphabet[i]-'a'] = i;

		cin >> M;
		for (int m = 0; m < M; m++){
			string W;
			cin >> W;
			words.push_back(W);
		}
		printInOrder(a, words, 0);
	}
}
