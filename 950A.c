#include<iostream>
using namespace std;

int main() {
	int l = 0, r = 0, a = 0, m = 0;
	cin >> l;
	cin >> r;
	cin >> a;
	m = abs(l-r);
	int res = 0;
	if(a >= m) 
		res = (a-m)&1 ? l+r+a-1:l+r+a;
	else
		res = 2*(a + min(l,r));
	cout << res << endl;
	return 0;
}
		
