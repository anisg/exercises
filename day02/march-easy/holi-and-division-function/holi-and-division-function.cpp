// Write your code here
#include <iostream>
#include <cmath>

using namespace std;

int F(double d){
	double n;
	if (modf(d, &n) >= 0.5)
		return ceil(d);
	else
		return floor(d);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		int N;
		cin >> N;
		double *A = new double[N];
		for (int i = 0; i < N; i++){
			int v;
			cin >> v;
			A[i] = (double)v;
		}
		double total = 0;
		for (int i = 0; i < N; i++){
			for (int j = i; j < N; j++){
				total += F(A[i]/A[j]) + F(A[j]/A[i]);
			}
		}
		cout << (int)total << endl;
	}
}
