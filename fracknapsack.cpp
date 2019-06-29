#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> i, pair<int, int> j){
	return ((float)(i.first) / (i.second)) >  ((float)(j.first) / (j.second));
}
int fracKnapsack(int W, int n, int val[], int wt[]){
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		v.push_back({val[i], wt[i]});
	}
	sort(v.begin(), v.end(), comp);
	int i = n - 1;
	float res = 0.0;
	while(W > 0 && i >= 0){
		if(wt[i] <= W)
		{
			W = W - wt[i];
			res += (float)val[i];
		}
		else {
			res += ((float)W/ wt[i]) * val[i];
			W = 0;
		}
		i--;
	}
 	return res;
}
int main(){
  	int W = 50; 
    int wt[] = {10, 20, 30}; 
    int val[] = {60, 100, 120}; 
    int n = sizeof(val)/sizeof(val[0]); 
    cout << fracKnapsack(W, n, val, wt) << endl; 
    return 0; 
}