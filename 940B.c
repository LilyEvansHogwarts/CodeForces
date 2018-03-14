#include<iostream>
using namespace std;

int main() {
	long long n = 0,k = 0,A = 0,B = 0;
	cin >> n;
	cin >> k;
	cin >> A;
	cin >> B;
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}
	if(k == 1) {
		cout << A*(n-1) << endl;
		return 0;
	}
	long long cost = 0;
	while(n >= k) {
		long long m1 = n/k;
		long long m2 = n-m1*k, m3 = A*(n-m2-m1);
		cost += m2 ? A*m2 : 0;
		cost += min(B,m3);
		n = m1;
	}
	cost += A*(n-1);
	cout << cost << endl;
	return 0;
}




