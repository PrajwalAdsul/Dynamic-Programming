#include<bits/stdc++.h>
using namespace std;
// Function overloading
// recursive
int fun(int a[], int i, int j){
	if(i == j)
		return a[i];
	if(j == i + 1)
		return max(a[i], a[j]);
	return max(a[i] + min(fun(a, i + 2, j), fun(a, i + 1, j - 1)),
		a[j] + min(fun(a, i, j - 2), fun(a, i + 1, j - 1)));
}
// DP way 1
#define MAX 1000
int fun(int a[], int i, int j, int dp[][MAX]){
	if(i == j)
		return a[i];
	if(j == i + 1)
		return max(a[i], a[j]);
	if(dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = max(a[i] + min(fun(a, i + 1, j - 1, dp), fun(a, i + 2, j, dp)),
		a[j] + min(fun(a, i + 1, j - 1, dp), fun(a, i, j - 2, dp)));
}
// DP way 2
// Most preffered way as we make 2D arraty only of required size
int fun(int a[], int n){
	int dp[n][n];
	for(int l = 0; l < n; l++){
		for(int i = 0, j = l; j < n; i++, j++){
				int x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
				int y = ((i + 1) <= (j - 1)) ? dp[i + 2][j - 1] : 0;
				int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;
				dp[i][j] = max(a[i] + min(x, y), a[j] + min(y, z)); 
		}
	}
	return dp[0][n - 1];
}
int main(){
	int a[4] = {5, 3, 7, 10};
	int n = sizeof(a)/ sizeof(a[0]);
	cout << fun(a, 0, n - 1) << endl;
	int dp[n + 1][MAX];
	memset(dp, -1, sizeof(dp));
	cout << fun(a, 0, n - 1, dp) << endl;
	cout << fun(a, n) << endl;
	return 0;
}