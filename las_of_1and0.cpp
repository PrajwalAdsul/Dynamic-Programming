#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10] = {1, 0, 0, 1, 0, 0, 1, 0, 1, 0};
	int n = sizeof(a)/ sizeof(a[0]);
	int max = INT_MIN;
	int dp[n];
	dp[n - 1] = 1;
	for(int i = n - 2; i >= 0; i--){
		if(a[i] ^ a[i + 1] == 1){
			dp[i] = dp[i + 1] + 1;
			if(dp[i] > max){
				max = dp[i];
			}
		}
		else
		{
			dp[i] = 1;
		}
	}
	cout << max << endl;
	return 0;
}