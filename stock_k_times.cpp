// C++ program to find out maximum profit by 
// buying and selling a share atmost k times 
// given stock price of n days 
#include <climits> 
#include <iostream> 
using namespace std; 

// Function to find out maximum profit by buying 
// & selling a share atmost k times given stock 
// price of n days 
int maxProfit(int price[], int n, int k) 
{ 
	int dp[k + 1][n + 1], maxx = INT_MIN;
	for(int i = 0; i <= k; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else{
				maxx = INT_MIN;
				for(int m = 0; m < j; m++){
					maxx = max(maxx, price[j] - price[m] + dp[i - 1][m]);
				}
				dp[i][j] = max(dp[i][j - 1], maxx);
			}
		}
	}
	return dp[k][n - 1];
} 
// Driver code 
int main() 
{ 
	int k = 2; 
	int price[] = { 10, 22, 5, 75, 65, 80 }; 
	int n = sizeof(price) / sizeof(price[0]); 

	cout << "Maximum profit is: "
		<< maxProfit(price, n, k); 

	return 0; 
} 
