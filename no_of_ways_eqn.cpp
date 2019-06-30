// A Dynamic programming based C++ 
// program to find number of non-negative 
// solutions for a given linear equation 
#include<bits/stdc++.h> 
using namespace std; 

// Returns count of solutions for 
// given rhs and coefficients coeff[0..n-1] 
int count(int coeff[], int n, int rhs) 
{ 
	int dp[rhs + 1] = {0};
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = coeff[i - 1]; j <= rhs; j++){
			dp[j] = dp[j] + dp[j - coeff[i - 1]];
		}
	}
	return dp[rhs];
} 

// Driver Code 
int main() 
{ 
	int coeff[] = {2, 2, 5}; 
	int rhs = 4; 
	int n = sizeof(coeff) / sizeof(coeff[0]); 
	cout << count(coeff, n, rhs); 
	return 0; 
} 
