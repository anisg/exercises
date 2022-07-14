#include <bits/stdc++.h>

using namespace std;

int A[100000+1];

void swapPtr(unordered_map<int,int> **pm1, unordered_map<int,int> **pm2){
	unordered_map<int,int> *tmp;
	tmp = (*pm1);
	(*pm1) = (*pm2);
	(*pm2) = tmp;
}

size_t resolve(int *A, int n, int m, int k){
	unordered_map<int,int> m1,m2;
	unordered_map<int,int> *map = &m1;
	unordered_map<int,int> *mn = &m2;

	int sol = 0;
	for (int i = 0; i < n; i += 1){
		for (pair<int, int>e : (*map)) {
			int n = ((size_t)e.first * A[i]) % (size_t)m;
			if (n == k){
				sol += e.second;
			}
			if ((*mn).count(n) == 0)
				(*mn)[n] = e.second;
			else
				(*mn)[n] += e.second;
		}
		if (A[i] % m == k){
			sol += 1;
		}
		if ((*mn).count(A[i] % m) == 0)
			(*mn)[A[i] % m] = 1;
		else
			(*mn)[A[i] % m] += 1;
		swapPtr(&map, &mn);
		*mn = {};
	}
	return sol;
}

vector<string> split_string(string);
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nmk_temp;
        getline(cin, nmk_temp);

        vector<string> nmk = split_string(nmk_temp);

        int n = stoi(nmk[0]);

        int m = stoi(nmk[1]);

        int k = stoi(nmk[2]);

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);
            A[i] = A_item;
        }

        long result = resolve(A, n, m, k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
