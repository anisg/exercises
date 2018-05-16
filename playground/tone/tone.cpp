#include <bits/stdc++.h>

using namespace std;

int resolve(int A)
{
	return 0;
}

string construct_str(string a, string b, string c)
{
	string ta,tb,tc;
	vector<string> v = {a,b,c};
	sort(v.begin(), v.end());
	/*
	ta = min(min(a,b), c);
	tc = max(max(a,b), c);
	if ((ta == a && tc == b) || (ta == b && tc == a))
		tb = c;
	else if ((ta == c && tc == b) || (ta == b && tc == c))
		tb = a;
	else
		tb = b;

	s << ta << "," << tb << "," << tc ;
	*/
	stringstream s;
	return s.str();
}

int main()
{
	int N;
	cin >> N;
	unordered_map<string,bool> m;
	int count = 0;

	for (int _ = 0; _ < N; _ += 1){
		string a,b,c;
		cin >> a >> b >> c;
		string s = construct_str(a,b,c);
		auto r = m.find(s);
		if (r == m.end()){
			count += 1;
			m.insert({s, true});
		} else {
			if (r->second == true){
				count -= 1;
				r->second = false;
			}
		}
	}
	cout << count << endl;
}
