// C++ program for no of steps. 1, 2, 3 steps allowed
#include<bits/stdc++.h> 
using namespace std; 
int count(int n){
	if(n < 0)
		return -1;
	if(n == 0 || n == 1 || n == 2)
		return n;
	if(n == 3)
		return 4;
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}
int main() 
{ 
	int n = 4; 
    printf("%d\n", count(n)); 
    return 0; 
} 