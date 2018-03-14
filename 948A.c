#include<iostream>
#include<vector>
#include<string>
using namespace std;

void decide(vector<string>& res,int h,int w) {
	auto valid = [&h,&w](const int& i,const int& j) {
		return i >= 0 && j >= 0 && i < h && j < w;
	};
	for(int i = 0;i < h;i++) {
		for(int j = 0;j < w;j++) {
			if(res[i][j] == 'W') {
				if(valid(i+1,j) && res[i+1][j] == 'S') {
					cout << "No" << endl;
					return;
				}
				if(valid(i,j+1) && res[i][j+1] == 'S') {
					cout << "No" << endl;
					return;
				}
			} else if(res[i][j] == 'S') {
				if(valid(i+1,j) && res[i+1][j] == 'W') {
					cout << "No" << endl;
					return;
				}
				if(valid(i,j+1) && res[i][j+1] == 'W') {
					cout << "No" << endl;
					return;
				}
				if(valid(i+1,j) && res[i+1][j] == '.') res[i+1][j] = 'D';
				if(valid(i-1,j) && res[i-1][j] == '.') res[i-1][j] = 'D';
				if(valid(i,j+1) && res[i][j+1] == '.') res[i][j+1] = 'D';
				if(valid(i,j-1) && res[i][j-1] == '.') res[i][j-1] = 'D';
			}
		}
	}
	cout << "Yes" << endl;
	for(int i = 0;i < h;i++)
		cout << res[i] << endl;
}
					

int main() {
	int h = 0, w = 0;
	cin >> h;
	cin >> w;
	vector<string> res(h,"");
	int i = 0;
	while(i < h)
		cin >> res[i++];
	decide(res,h,w);
	return 0;
}
