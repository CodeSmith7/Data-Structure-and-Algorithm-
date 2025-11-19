#include <bits/stdc++.h> 

const int MOD = 1e9+7;
int cntSubset(int idx, vector<int> &arr, int tar, vector<vector<int>>& dp ) {
    if ( idx == 0) {
        if (tar == 0 && arr[0] == 0) return 2;
        if (tar == 0) return 1;
        if (arr[0] == tar) return 1;
        return 0;
    }

    if ( dp[idx][tar] != -1) {
        return dp[idx][tar];
    }

    int nottake = cntSubset(idx-1, arr,tar, dp) % MOD;
    int take = 0;
    if ( arr[idx] <= tar) {
        take = cntSubset(idx-1, arr, tar - arr[idx], dp) % MOD;
    }

    return dp[idx][tar] = (take + nottake) % MOD;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int totsum = 0;

    for ( int &ele : arr) {
        totsum += ele;
    }
    if (d > totsum) return 0;
    if ((totsum - d) %2 != 0) return 0;

    int s = (totsum - d)/2;

    vector<vector<int>> dp ( n, vector<int>(s+1,-1));

    return cntSubset(n-1, arr, s, dp);

}


//using tabulation

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int totsum = 0;

    for ( int &ele : arr) {
        totsum += ele;
    }
    if (d > totsum) return 0;
    if ((totsum - d) %2 != 0) return 0;

    int s = (totsum - d)/2;

    vector<vector<int>> dp ( n, vector<int>(s+1,0));

    if (arr[0] == 0) {
        dp[0][0] = 2;
    } else {
        dp[0][0] = 1;
    }

    if(arr[0]!=0 && arr[0] <= s) dp[0][arr[0]] = 1;


    for ( int i = 1; i < n;i++)  {
        for (int sum = 0; sum <= s; sum++ ) {
            int nottake = dp[i-1][sum];
            int take = 0; 
            if (arr[i] <= sum) {
                take = dp[i-1][sum -arr[i]];
            }

            dp[i][sum] = (take + nottake) % MOD;
        }
    }

    return dp[n-1][s];


}


//space optimization 

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int totsum = 0;

    for ( int &ele : arr) {
        totsum += ele;
    }
    if (d > totsum) return 0;
    if ((totsum - d) %2 != 0) return 0;

    int s = (totsum - d)/2;



    vector <int> prev (s+1, 0), curr(s+1, 0);

    if (arr[0] == 0) {
        prev[0] = 2;
    } else {
        prev[0] = 1;
    }

    if(arr[0]!=0 && arr[0] <= s) prev[arr[0]] = 1;


    for ( int i = 1; i < n;i++)  {
        for (int sum = 0; sum <= s; sum++ ) {
            int nottake = prev[sum];
            int take = 0; 
            if (arr[i] <= sum) {
                take = prev[sum -arr[i]];
            }

            curr[sum] = (take + nottake) % MOD;
        }
        prev = curr;
    }

    return prev[s];


}






