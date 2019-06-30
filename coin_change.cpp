// C++ program for coin change problem. 
#include<bits/stdc++.h> 
using namespace std; 
int count( int a[], int m, int n ) 
{ 
	int dp[n + 1] = {0};
	dp[0] = 1;
	for(int i = 1; i <= m; i++){
		for(int j = a[i - 1]; j <= n; j++){
			dp[j] = dp[j] + dp[j - a[i - 1]];
		}
	}
	return dp[n];
} 
int main() 
{ 
	int arr[] = {1, 2, 3}; 
	int m = sizeof(arr)/sizeof(arr[0]); 
	int n = 4; 
	cout << count(arr, m, n); 
	return 0; 
} 