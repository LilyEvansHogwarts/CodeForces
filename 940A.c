#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cut(int n,int d,int i,int j,vector<int>& res,vector<vector<int>>& dp) {
	if(dp[i][j] < n) return dp[i][j];
	if(res[j]-res[i] <= d) 
		return dp[i][j] = n+i-j-1;
	if(j == i+1)
		return dp[i][j] = n-1;
	int p1 = res[i+1]-res[i], p2 = res[j]-res[j-1];
	if(p1 > p2)
		return dp[i][j] = cut(n,d,i+1,j,res,dp);
	else if(p1 < p2)
		return dp[i][j] = cut(n,d,i,j-1,res,dp);
	else
		return dp[i][j] = min(cut(n,d,i+1,j,res,dp),cut(n,d,i,j-1,res,dp));
}

int main() {
	int n = 0, d = 0;
	cin >> n;
	cin >> d;
	int a = 0;
	vector<int> res;
	vector<vector<int>> dp(n,vector<int>(n,n));
	while(cin >> a)
		res.push_back(a);
	sort(res.begin(),res.end());
	cout << cut(n,d,0,n-1,res,dp) << endl;
	return 0;
}
