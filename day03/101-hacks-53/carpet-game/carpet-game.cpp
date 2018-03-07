#include <iostream>
#include <cmath>

using namespace std;

vector<string> split_string(string);


/*
 * Complete the howManyWays function below.
 */
float     fact(float a){
	return tgamma(a+1);
}

long permutCount(int n){
	return fact(n);
}
char get(char *A, int n,int m,int x, int y){
	return A[m*y + x];
}
void propage(char *A, int pos, char *putted){
	for (int i = 0; putted[i] != -1; i++){

	}
}

void isPossible(int x,int y, vector< pair<int,int> > &putted)
{
	for (size_t i =0; i < putted.size(); i++)
	{
		int x2 = putted[i].first;
		int y2 = putted[i].second;
	}
}

void put(char *A, int n, int m, int x, int y){
	int pos = m*y+x;
	if (A[pos] == 0 && isPossible){
		A[pos] = 1;
		propage(A,n,m,x,y);
	}
}

long test(char *A, int n, int m, int inY, int inX,
	pair<int, int>*putted, int remain, int total)
{
	long count = 0;
	for (y=inY; y < n; y++){
		for (x=inX; x < m; x++){
			if (get(A,n,m,x,y) != -1){
				put(A,n,m,x,y, putted, &remain);
				if (remain == 0){
					count += permutCount(total) % lim;
				} else {
					count += test(A, n,m, y, x+1, putted, remain, total) % lim;
				}
				unput(A,n,m,x,y, putted, &remain);
			}
		}
	}
	return count % lim;
}

int howManyWays(int n, int m, long k) {
	// Return the number of ways modulo 10^9+7.
	char *A = new char[n*m]();
	return test() +
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int d;
    cin >> d;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int d_itr = 0; d_itr < d; d_itr++) {
        string nmk_temp;
        getline(cin, nmk_temp);

        vector<string> nmk = split_string(nmk_temp);

        int n = stoi(nmk[0]);

        int m = stoi(nmk[1]);

        long k = stol(nmk[2]);

        int result = howManyWays(n, m, k);

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
