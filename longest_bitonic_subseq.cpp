// C++ program to find length of longest bitonic subsequence
#include <bits/stdc++.h>
using namespace std; 
int fun(int a[], int n) 
{ 
	int lis[n] = {0}, rlis[n] ={0};
	lis[0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[j] < a[i])
				lis[i] = max(lis[i], lis[j] + 1);
		}
	}
	rlis[n - 1] = 1;
	for(int i = n - 1; i >= 0; i--){
		for(int j = n - 1; j > i; j--){
			if(a[j] < a[i]){
				rlis[i] = max(rlis[i], rlis[j] + 1);
			}
		}
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		res = max(res, lis[i] + rlis[i]);
	}
	return res;
} 
// Driver code 
int main() 
{ 
	int a[10] = {4, 6, 1, 2, 9, 3, 6, 7, 5, 8};
	int n = sizeof(a) / sizeof(a[0]);
	cout << fun(a, n) << endl;

	return 0; 
} 
