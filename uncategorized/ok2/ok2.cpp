#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int count = 0;
	for (int _ = 0; _ < T; _ += 1){
		//resolve here
		float a,b,c;
		cin >> a >> b >> c;
		if (b*b - 4.0*a*c >= 0)
			count += 1;
	}
	cout << count << endl;
}
