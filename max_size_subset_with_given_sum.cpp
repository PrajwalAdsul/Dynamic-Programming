#include<bits/stdc++.h>
using namespace std;
int maxsizesubset(int a[], int n, int sum){
	int count[sum + 1][n + 1], maxx = INT_MIN;
	bool dp[sum + 1][n + 1];
	memset(count, 0, sizeof(count));
	memset(dp, false, sizeof(dp));
	for(int i = 0; i <= sum; i++){
		for(int j = 1; j <= n; j++){
			if(i == 0){
				count[i][j] = 0;
				dp[i][j] = true;
			}
			else if(j == 0){
				count[i][j] = -1;
				dp[i][j] = false;
			}
			else{
				dp[i][j] = dp[i][j - 1];
				count[i][j] = count[i][j - 1];
				if(a[j - 1] <= i){
					dp[i][j] = dp[i][j] || dp[i - a[j - 1]][j - 1];
					if(dp[i][j])
						count[i][j] = max(count[i][j - 1], count[i - a[j - 1]][j] + 1);
					if(count[i][j] > maxx){
						maxx = count[i][j];
					}
				}
			}
		}
	}
	return maxx;
}
int main(){
	int a[10] = {6, 3, 1, 2, 9 , 4, 5, 0, 7, 8};
	int n = sizeof(a)/ sizeof(a[0]);
	cout << maxsizesubset(a, n, 10);

	cout << endl;
	return 0;
}