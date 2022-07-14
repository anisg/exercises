#include <bits/stdc++.h>

using namespace std;

/* ---------------------------------------- */
/* -------------    Utility      ---------- */

//str(), print()
template<typename T> string str(T & a){ return to_string(a); }
template<typename T> void print(T s){ cout << str(s) << "\n"; }


/* ---------------------------------------- */
/* -------------     Debug       ---------- */

//operator '<<' on vector
template <typename T>
ostream& operator<<(ostream& os, vector<T> & v) {
	os << "[";
	for (size_t i = 0; i < v.size(); i += 1){
		os << v[i];
		if (i + 1 < v.size())
			os << ", ";
	}
	os << "]";
	return os;
}

int main()
{
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout << v << endl;
}
