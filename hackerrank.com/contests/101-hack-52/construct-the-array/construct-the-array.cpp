// Write your code here
#include <iostream>
#include <cmath>

using namespace std;

float     fact(float a){
    return tgamma(a+1);
}
long combination(int n, int r){
	return (fact(n)/(fact(r)*(fact(n-r))));
}

long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
	return combination(k, n-2);
}

int main() {
    int n;
    int k;
    int x;
    cin >> n >> k >> x;
    long answer = countArray(n, k, x);
    cout << answer << endl;
    return 0;
}
