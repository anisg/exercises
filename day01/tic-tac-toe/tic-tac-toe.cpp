// Write your code here
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;										// Reading input from STDIN
	for (int t = 1; t <= T; t++){
		int max = 1000000000 + 7;
		int n;
		cin >> n;
		int maxi = 0;
		int m = 0;
		for (int i = n-1; i > 0; i -= 1){
			maxi += pow(i, 2);
			m += i;
		}
		cout << ((m) % max) << " " << (maxi % max) << endl;
	}
}
