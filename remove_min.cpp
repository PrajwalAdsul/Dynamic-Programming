// C++ program to remove min elements from either side such that 2 * min becomes more than max
#include<bits/stdc++.h>
using namespace std;
#define min(a, b) ( (a < b) ? a : b)
int minn(int a[], int i, int j){
	int mini = INT_MAX;
	for(int k = i; k <= j; k++){
		mini = min(a[k], mini);
	}
	return mini;
}
int maxx(int a[], int i, int j){
	int maxi = INT_MIN;
	for(int k = i; k <= j; k++){
		maxi = max(a[k], maxi);
	}
	return maxi;
}
int fun(int a[], int i, int j, int dp[][100]){
	if(j <= i)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int min = minn(a, i, j);
	int max = maxx(a, i, j);
	if(2 * min > max)
		return 0;
	return dp[i][j] = min(fun(a, i + 1, j, dp), fun(a, i, j - 1, dp)) + 1;
}
int main(){
	int a[6] = {20, 7, 5, 15 , 30, 6};
	int n = sizeof(a) / sizeof(a[0]);
	int dp[n][100];
	memset(dp, -1, sizeof(dp));
	cout << fun(a, 0, n - 1, dp) << endl;
	return 0;
}