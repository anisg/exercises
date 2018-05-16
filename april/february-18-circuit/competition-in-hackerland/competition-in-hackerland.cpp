#include <bits/stdc++.h>

using namespace std;

double calcDistance(double distance, int strength)
{
	return strength/log2(2.0 + distance);
}

double sumDistance(int a, int b, vector<pair<double, int>> & arr, double trophy){
	double result;

	result = 0.0;
	for (int x = a; x <= b; x += 1){
		result += calcDistance(abs(arr[x].first - trophy), arr[x].second);
	}
	return (result);
}

double f(vector<pair<double, int>> & arr, double mid){
	int n = arr.size();
	int x = floor(mid); //down
	return sumDistance(0, x, arr, mid) - sumDistance(x+1, n-1, arr, mid);
}

vector<double> solveDistance(int N, vector<pair<double, int>> & arr)
{
	vector<double> result; //pos
	sort(arr.begin(), arr.end());
	for (int i = 1; i < N; i += 1)
	{
		double l = arr[i - 1].first;
		double r = arr[i].first;
		double m = 0.0;
		for (int _ = 0; _ < 100; _ += 1){
			m = abs(r - l) / 2;
			cout << f(arr, m) << endl;
			if (f(arr, m) < 0)
				r = m;
			else
				l = m;
		}
		cout << "__" << f(arr, m) << endl;
		if (m <= 1e-9){
			result.push_back(m);
		}
	}
	return result;
}

int main()
{
	int N;
	cin >> N;
	vector<double> arrDist;
	for (int i = 0; i < N; i+= 1){
		double v;
		cin >> v;
		arrDist.push_back(v);
	}
	vector<int> arrStrength;
	for (int i = 0; i < N; i+= 1){
		int v;
		cin >> v;
		arrStrength.push_back(v);
	}
	//merge both array
	vector<pair<double, int>> arr;
	for (int i = 0; i < N; i+= 1){
		arr.push_back(make_pair(arrDist[i], arrStrength[i]));
	}
	vector<double> res;
	res = solveDistance(N, arr);
	cout << res.size() << endl;
	for (size_t i = 0; i < res.size(); i += 1){
		cout << res[i] << (i + 1 < res.size() ? " " : "");
	}
	cout << endl;
}
