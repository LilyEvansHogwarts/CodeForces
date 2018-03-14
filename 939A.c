#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n = 0;
	cin >> n;
	vector<int> res(n,0);
	int p = 0;
	while(p < n)
		cin >> res[p++];
	for(int i = 0;i < n;i++) {
		int m1 = res[i], m2 = 0, m3 = 0;
		if(m1 <= n) m2 = res[m1-1];
		else continue;
		if(m2 <= n) m3 = res[m2-1];
		else continue;
		if(m3 == i+1 && m1 != m2 && m3 != m2 && m1 != m3) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
