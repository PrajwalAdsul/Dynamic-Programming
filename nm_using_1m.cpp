// C++ program n * m using 1 * m
#include<bits/stdc++.h>
using namespace std;
// Recursive
int funrec(int n, int m){
	if(n == m)
		return 2;
	if(n >= 1  && n < m)
		return 1;
	if(n <= 0 || m <= 0)
		return 0;
	return funrec(n - 1, m) + funrec(n - m, m);
}
// Dp
int fun(int n, int m){
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = 1;
	}
	dp[m] = 2;
	for(int i = m + 1; i <= n; i++){
		dp[i] = dp[i - 1] + dp[i - m];
	}
	return dp[n];
}
int main(){
	 int n = 7, m = 4; 
    cout << "Number of ways = "
         << fun(n, m); 
	cout << endl;
	return 0;
}