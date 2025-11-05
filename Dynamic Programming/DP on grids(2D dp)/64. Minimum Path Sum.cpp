// Recursion + memoization
class Solution {
public:
    vector <vector<int>> t;
    int solve ( int row, int col, vector<vector<int>>& grid) {
        if ( row == 0 && col == 0) {
            return grid[0][0];
        }
        if ( row < 0 || col < 0) {
            return INT_MAX;
        }

        if (t[row][col] != -1) {
            return t[row][col];
        }
        
        int up = INT_MAX, left = INT_MAX;

        if ( row > 0) up = grid[row][col] + solve (row-1, col, grid);
        if ( col > 0) left = grid[row][col] +solve ( row, col - 1, grid);

        return t[row][col] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        t.resize(n,vector<int>(m,-1));

        return solve(n-1, m-1, grid);
    }
};


//tabulation 
class Solution {
public:
   
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int> (m,0));

        for ( int i = 0; i< n; i++) {
            for ( int j = 0; j< m; j++) {
                if ( i==0 && j == 0) {
                    dp[i][j] = grid[0][0];
                } else {
                    int up = INT_MAX;
                    int left = INT_MAX;

                    if (i > 0) up= grid[i][j] + dp[i-1][j];
                    if ( j >0) left = grid[i][j] + dp[i][j-1];

                    dp[i][j] = min(up, left);
                }
            }

            
        }
        return dp[n-1][m-1];
    }
};


//space optimzation 
class Solution {
public:
   
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev (m,0);

        for ( int i = 0; i< n; i++) {
            vector <int> curr (m,0);
            for ( int j = 0; j< m; j++) {
                if ( i==0 && j == 0) {
                    curr[j] = grid[0][0];
                } else {
                    int up = INT_MAX;
                    int left = INT_MAX;

                    if (i > 0) up= grid[i][j] + prev[j];
                    if ( j >0) left = grid[i][j] + curr[j-1];

                    curr[j] = min(up, left);
                }
            }
            prev = curr;

            
        }
        return prev[m-1];
    }
};
