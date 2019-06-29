#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int a[], int n, int sum){
	bool dp[n + 1][sum + 1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			if(i == 0)
			{
				dp[i][j] = false;
			}
			else if(j == 0)
			{
				dp[i][j] = true;
			}
			else if(j >= a[i - 1]){
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
			}
			else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][sum];
}	

int main(){
	int a[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	int n = sizeof(a) / sizeof(a[0]);
 	cout << subsetsum(a, n, 21) << endl; 
    return 0; 
}