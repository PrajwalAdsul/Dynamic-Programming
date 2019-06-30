// C++ program dice with m faces numbered 1 to m, find ways for getting sum x in n trails
#include<bits/stdc++.h>
using namespace std;
int fun(int m, int n, int x){
	int dp[n + 1][x + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= m && i <= x; i++)
		dp[1][i] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= x; j++){
			for(int k = 1; k <= m; k++){
				if(j > k)
					dp[i][j] = dp[i][j] + dp[i - 1][x - k];
			}
		}
	}
	return dp[n][x];
}
int main(){
	cout << fun(6, 3, 8) << endl;
	return 0;
}