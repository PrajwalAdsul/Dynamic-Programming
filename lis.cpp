#include<bits/stdc++.h>
using namespace std;
int lis(int a[], int n){
	int dp[n];
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[j] <= a[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return dp[n - 1];
}
int main(){
	int a[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	int n = sizeof(a) / sizeof(a[0]);
 	cout << lis(a, n) << endl; 
    return 0; 
}