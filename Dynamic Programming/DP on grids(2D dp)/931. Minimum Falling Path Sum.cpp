//Recursion + memoization (but it gives the TLE) 
class Solution {
public:
    vector<vector<int>> t;
    int solve ( int i, int j, vector<vector<int>>& matrix) {
        if ( i == matrix.size()-1) {
            return matrix[i][j];
        }
        if ( t[i][j] != -1) {
            return t[i][j];
        }

        int left = INT_MAX, down = INT_MAX, right = INT_MAX;

        if ( j > 0) left = matrix[i][j] + solve (i+1,j-1, matrix);
        if ( j < matrix.size()-1) right = matrix[i][j] + solve (i+1, j+1, matrix);
        down = matrix[i][j] + solve (i+1, j, matrix);

        return t[i][j] = min(left, min(right, down));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;

        int n = matrix.size();

        t.resize(n,vector<int>(n,-1));

        for ( int i = 0; i < matrix.size(); i++) {
            ans = min ( ans , solve (0, i, matrix));
        }

        return ans;
    }
};


//  using  tabulation 


class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for ( int i = 0; i < n; i++) {
            dp[n-1][i] = matrix[n-1][i];
        }

        for ( int i = n-2; i>=0; i--) {
            for ( int j = 0; j < n; j++) {
                int ld = INT_MAX, u, rd = INT_MAX;
                u = matrix[i][j] + dp[i+1][j];
                if (j > 0)  ld = matrix[i][j] + dp[i+1][j-1];
                if ( j +1 < n) rd = matrix[i][j] + dp[i+1][j+1];

                dp[i][j] = min(u, min(ld,rd));
            }
        }

        int ans = INT_MAX;

        for ( int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);

        }


        return ans;

        
    }
};

//space optimization 

class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);

        for ( int i = 0; i < n; i++) {
            prev[i] = matrix[n-1][i];
        }

        for ( int i = n-2; i>=0; i--) {
            vector<int> curr(n, 0);
            for ( int j = 0; j < n; j++) {
                int ld = INT_MAX, u, rd = INT_MAX;
                u = matrix[i][j] + prev[j];
                if (j > 0)  ld = matrix[i][j] + prev[j-1];
                if ( j +1 < n) rd = matrix[i][j] + prev[j+1];

                curr[j] = min(u, min(ld,rd));
            }
            prev = curr;
        }

        int ans = INT_MAX;

        for ( int i = 0; i < n; i++) {
            ans = min(ans, prev[i]);

        }


        return ans;

        
    }
};
