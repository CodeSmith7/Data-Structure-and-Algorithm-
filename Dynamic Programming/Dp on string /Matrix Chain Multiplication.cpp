
//using memoization
class Solution {
  public:
    vector<vector<int>> t;
    int solve ( int i, int j,vector<int> &arr ) {
        if ( i >= j) {
            return 0;
        }
        
        if ( t[i][j] != -1) {
            return t[i][j];
        }
        
        int ans = INT_MAX;
        
        for ( int k = i; k <= j-1; k++) {
            int tempans = solve (i, k, arr) + solve (k+1, j, arr) + arr[i-1]*arr[k]*arr[j];
            if (tempans < ans ) {
                ans = tempans;
            }
        }
        
        return t[i][j] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        t.resize(n, vector<int>(n, -1));
        
        int i = 1;
        int j = arr.size()-1;
        return solve (i, j, arr);
    }
};

//using tabulation
class Solution {
  public:
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp (n, vector<int>(n, 0));
        
        for( int i =1 ; i< n; i++) {
            dp[i][i] = 0;
        }
        
        for ( int i = n-1; i>= 1; i--) {
            for (int j = i+1; j < n; j++) {
                int mini = INT_MAX;
                for ( int k = i; k < j; k++) {
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] +dp[k+1][j];
                    
                    if ( steps < mini) {
                        mini = steps;
                    }
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][n-1];
        
        
    }
};
