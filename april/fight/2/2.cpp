#include <bits/stdc++.h>

using namespace std;

int minutes(double v, double d)
{
	return ceil(d/v * 60.0);
}

int resolve(double t0, double t1, double t2, double v1, double v2, double d)
{
	int m = INT_MAX;
	if (t0 > t1 && t0 > t2)
		return -1;
	if (t0 >= t1)
		m = min(m, minutes(v1, d));
	if (t0 >= t2)
		m = min(m, minutes(v2, d));
	return (int)t0 + (int)m;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i += 1){
		double t0, t1, t2, v1, v2, d;
		cin >> t0 >> t1 >> t2 >> v1 >> v2 >> d;
		cout << resolve(t0, t1, t2, v1, v2, d) << endl;
	}
}
