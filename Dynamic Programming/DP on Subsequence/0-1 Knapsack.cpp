
#include <bits/stdc++.h>

int solve ( int idx, int *values,int *weights, int maxWeight, vector<vector<int>>& dp) {
	if (idx == 0) {
		if (weights[0] <= maxWeight) return values[0];
		else return 0;
	}

	if (dp[idx][maxWeight] != -1) {
		return dp[idx][maxWeight];
	}
 
	int nottake = solve (idx-1,values, weights, maxWeight, dp);
	int take = INT_MIN;
	if ( weights[idx] <= maxWeight) {
		take = values[idx] + solve ( idx-1, values, weights, maxWeight-weights[idx], dp);
	}
	return dp[idx][maxWeight] =  max (take, nottake);
}
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight+1,-1));

	return solve (n-1, values, weights, maxWeight, dp);
}


//using tabulation 

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight+1 , 0));

	for ( int w = weights[0]; w <= maxWeight; w++ ) {
		dp[0][w] = values[0];
	}

	for ( int idx = 1; idx < n; idx++) {
		for ( int w = 0; w <= maxWeight; w++) {
			
			int nottake = dp[idx-1][w];
			int take = INT_MIN;
			if ( weights[idx] <= w) {
				take = values[idx] + dp[idx-1][w - weights[idx]];
			}
			dp[idx][w] =  max (take, nottake);		 
		}
	}

	return dp[n-1][maxWeight];
}

space optimixzation using two vector


int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight+1 , 0));

	vector<int> prev(maxWeight+1,0), curr(maxWeight+1,0);


	for ( int w = weights[0]; w <= maxWeight; w++ ) {
		prev[w] = values[0];
	}

	for ( int idx = 1; idx < n; idx++) {
		for ( int w = 0; w <= maxWeight; w++) {
			
			int nottake = prev[w];
			int take = INT_MIN;
			if ( weights[idx] <= w) {
				take = values[idx] + prev[w - weights[idx]];
			}
			curr[w] =  max (take, nottake);		 
		}
		prev = curr;
	}

	return curr[maxWeight];
}


//space optimixzation using the one vector only 
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	vector<int> curr(maxWeight+1, 0);

	for ( int w = weights[0]; w <= maxWeight; w++ ) {
		curr[w] = values[0];
	}

	for ( int idx = 1; idx < n; idx++) {
		for ( int w = maxWeight; w >= 0; w--) {
			
			int nottake = curr[w];
			int take = INT_MIN;
			if ( weights[idx] <= w) {
				take = values[idx] + curr[w - weights[idx]];
			}
			curr[w] =  max (take, nottake);		 
		}
	}

	return curr[maxWeight];
}
