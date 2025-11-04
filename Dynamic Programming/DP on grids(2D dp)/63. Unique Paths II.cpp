class Solution {
public:
    vector<vector<int>> t;
    int solve ( int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& t) {
        if ( row < 0 || col < 0 || obstacleGrid[row][col] == 1) {
            return 0;
        }
        if ( row == 0 && col == 0) {
            return 1;
        }

        if (t[row][col] != -1) return t[row][col];

        int up = solve (row-1, col, obstacleGrid,t);
        int left = solve ( row, col-1, obstacleGrid,t);

        return t[row][col] = up + left;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> t(n, vector<int>(m,-1));

        return solve (n-1, m-1, obstacleGrid, t);
        
    }
};


//using tabulation 

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 0));

        for ( int i = 0; i< n; i++) {
            for ( int j = 0; j < m; j++) {
                if ( obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i == 0 && j == 0)  {
                    dp[i][j] = 1;
                }  else {
                    int up = 0, left = 0;

                    if (i > 0) up = dp[i-1][j];
                    if ( j > 0) left = dp[i][j-1];

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[n-1][m-1];
        
    }
};


//tabulation using space optimization 

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<int> prev(m,0);

        for ( int i = 0; i< n; i++) {
            vector<int> curr(m,0);
            for ( int j = 0; j < m; j++) {
                if ( obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else if (i == 0 && j == 0)  {
                    curr[j] = 1;
                }  else {
                    int up = 0, left = 0;

                    if (i > 0) up = prev[j];
                    if ( j > 0) left = curr[j-1];

                    curr[j] = up + left;
                }
            }
            prev = curr;

        }
        return prev[m-1];
        
    }
};
