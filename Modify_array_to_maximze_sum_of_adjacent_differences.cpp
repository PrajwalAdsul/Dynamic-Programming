// Modify array to maximze sum of adjacent differences
#include <bits/stdc++.h> 
using namespace std; 
// Recursive
void fun(int a[], int n, int *res, int index, int now){
	if(index >= n)
		return;
	if(index == 0){ 
		int temp = a[0];
		a[0] = 1;
		fun(a, n, res, index + 1, 0);
		a[0] = temp;
		fun(a, n, res, index + 1, 0);
	}
	else{
		*res = max(abs(a[index] - a[index - 1]) + now, *res);

		fun(a, n, res, index + 1, abs(a[index] - a[index - 1]) + now);
		
		int temp = a[index];
		a[index] = 1;
		*res = max(abs(1 - a[index - 1]) + now, *res);
		
		fun(a, n, res, index + 1, abs(1 - a[index - 1]) + now);
		a[index] = temp;
	}
}
// Dynamic Programming
int funmain(int a[], int n){
	int res = 0;
	fun(a, n, &res, 0, 0);
	return res;
}
int funn(int a[], int n){
	int dp[n][2];
	if(n == 0)
		return -1;
	dp[0][0] = 0;
	dp[0][1] = 0;
	for(int i = 1; i < n; i++){

		dp[i][0] = max(dp[i - 1][0] + abs(a[i - 1] - a[i]), dp[i - 1][1] + abs(1 - a[i]));
		dp[i][1] = max(dp[i - 1][0] + abs(1 - a[i - 1]), dp[i - 1][1]);
	}
	return max(dp[n - 1][0], dp[n - 1][1]);
}
int main() 
{ 
	int a[5] = {3, 2, 1, 4, 5};
	int n = sizeof(a) / sizeof(a[0]);
	cout << funn(a, n);
	cout << endl;
	return 0; 
} 
