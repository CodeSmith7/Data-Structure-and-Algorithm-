
//Recursion + memoization
class Solution {
public:
    int solve (int row, int col, vector <vector<int>>& t) {
        if (row == 0 && col == 0) {
            return 1;
        }
        if (row<0 || col <0) {
            return 0;
        }

        if (t[row][col] != -1 ) {
            return t[row][col];
        }
        int up = solve(row-1, col, t);
        int left = solve ( row, col -1, t);
        return t[row][col] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n,-1));

        return solve (m-1,n-1,t);
    }
};

//tabulation 

class Solution {
public:

    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m, vector<int>(n,0));

       for ( int i = 0; i < m; i++) {
        for ( int j = 0; j < n;j++) {
            if ( i == 0 && j == 0) dp[i][j] = 1;
            else {
                int up = 0, left = 0;

                if (i > 0) up = dp[i-1][j];
                if ( j > 0) left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }
       }
       return dp[m-1][n-1];
    }
};

//tabulation + space optimization 
class Solution {
public:

    int uniquePaths(int m, int n) {
       vector<int> prev(n,0);

       for ( int i = 0; i < m; i++) {
        vector<int> curr(n,0);
        for ( int j = 0; j < n;j++) {
            if ( i == 0 && j == 0) curr[j] = 1;
            else {
                int up = 0, left = 0;

                if ( i > 0)up = prev[j];
                if ( j > 0) left = curr[j-1] ;

                curr[j] = up + left;
            }
        }
        prev = curr;
       }
       return prev[n-1];
    }
};
