// Write your code here
#include <iostream>
#include <cmath>

using namespace std;
int lim = 1000000000 + 7;
const int primes[] = {
2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
811, 821, 823, 827, 829, 839, 853, 857, 859, 863,
877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013,
1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,
1087, 1091, 1093, 1097, 1103, 1109, 1117, -1
};
struct digitString {
	string s;
	int total;
	digitString(string s, int total): s(s), total(total) {}
};

int initH(string s){
	int total = 0;
	for (size_t i = 0; i < s.length(); i++){
		total += s[i] - '0';
	}
	return total;
}

int H(digitString & s){
	return s.total;
}

void div(digitString & s, int i){
	s.s[i] = '9';
	s.total += 9;
	if (i == 0){
	}
	else if (s.s[i-1] == '0') {
		div(s, i-1);
	} else {
		s.s[i-1] -= 1;
		s.total -= 1;
	}
}

void decrease(digitString & s){
	size_t n = s.s.length();
	if (s.s[n-1] == '0'){
		div(s, n-1);
	} else {
		s.s[n-1] -= 1;
		s.total -= 1;
	}
}

/*
int 	fact(float a){
	return (int)tgamma(a) % lim;
}

int nb_ways(int a, int b){
	int n = max(a,b);
	int r = min(a,b);

	return (fact(n) / fact(n - r)) % lim;
}*/

int main() {
	string v;
	cin >> v;
	digitString s = digitString(v, initH(v));
	int max_d = H(s);
	int *counter = new int[1200] ();
	int *is_prime = new int[1200] ();
	//set the is_prime array:
	for (int i = 0; primes[i] != -1; i++){
		is_prime[primes[i]] = true;
	}
	//set the counter array:
	while (H(s) > 0){
		counter[H(s)] += 1;
		max_d = max(max_d, H(s));
		decrease(s);
	}
	counter[0] += 1;
	int max_prime = 0;
	//get the sum of ways
	int possi = 0;
	for (int i = 1; i <= max_d; i++){
		for (int j = 0; j < i; j++){
			if (is_prime[i + j]){
				possi = (possi + (counter[i] * counter[j])) % lim;
			}
		}
	}
	cout << possi << endl;
}
