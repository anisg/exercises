#include <bits/stdc++.h>

using namespace std;

long long resolve(long long n,long long m, int a, int b){
	if (n % m == 0) return 0;
	return min( ((n < m) ? n : (n-m))*b, ((((n/m)+1) * m) - n) * a );
}

int main(){
	long long n,m,a,b;

	//parsing
	cin >> n >> m >> a >> b;
	//find solution
	cout << resolve(n,m,a,b) << "\n";
}
