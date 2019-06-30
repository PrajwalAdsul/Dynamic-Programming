// C++ program for no of ways to write n as sum of two or more positive ints 
#include<bits/stdc++.h> 
using namespace std; 
int count(int n) 
{ 
	int dp[n + 1] = {0};
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = i; j <= n; j++){
			dp[j] = dp[j] + dp[j - i];
		}
	}
	return dp[n];
} 

// Driver Code 
int main() 
{ 
	cout << count(5); 
	return 0; 
} 
