#include <bits/stdc++.h> 
using namespace std; 
int MatrixChainOrder(int a[], int n){
	int dp[n][n];
	for(int i = 1; i < n; i++)
		dp[i][i] = 0;
	for(int l = 2; l < n; l++){
		for(int i = 1; i < n - l + 1; i++){
			int j = i + l - 1;
			dp[i][j] = INT_MAX;
			for(int k = i; k <= j - 1; k++){
				int cost = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];
				if(cost < dp[i][j]){
					dp[i][j] = cost;
				}
			}
		}
	}
	return dp[1][n - 1];
}
int main() 
{ 
	int arr[] = {1, 2, 3, 4}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, n));   
	return 0; 
} 
