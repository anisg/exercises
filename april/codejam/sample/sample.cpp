#include <bits/stdc++.h>

using namespace std;

string getIn(){
	string s;
	cin >> s;
	return s;
}

int mid(int a, int b){
	return a + (abs(b-a)/2);
}

void sample() {
	int A,B,N;
	cin >> A >> B;
	cin >> N;

	for (int n = 0; n < N; n += 1){
		cout << mid(A,B) << endl;

		string in = getIn();
		if (in == "TOO_BIG"){
			A = mid(A,B);
		} else if (in == "TOO_SMALL") {
			B = mid(A,B);
		} else {
			break;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int _ = 0; _ < T; _ += 1){

	}
	cout << T << endl;
}
