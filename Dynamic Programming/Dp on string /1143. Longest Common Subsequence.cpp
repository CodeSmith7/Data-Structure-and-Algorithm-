// recursion + memoization 
class Solution {
public:
    int solve ( int ind1, int ind2, vector<vector<int>>& dp, string& text1, string& text2) {
        //pass string as a reference only 
        if ( ind1 < 0 || ind2 < 0) {
            return 0;
        }
        if (dp[ind1][ ind2] != -1) {
            return dp[ind1][ ind2];
        }

        if ( text1[ind1] == text2[ind2]) {
            return 1+ solve (ind1-1, ind2 -1, dp, text1, text2);
        }

        return dp[ind1][ind2] = max (solve (ind1-1,ind2, dp,text1, text2), solve (ind1, ind2-1, dp, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m,-1));

        return solve(n-1, m-1 , dp, text1, text2);
    }
};




//tabulation 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i = 0; i <n; i++) {
            dp[i][0] = 0;
        }
        for ( int j = 0; j<  m; j++) {
            dp[0][j] = 0;
        }

        for ( int ind1 = 1; ind1 <= n; ind1++) {
            for ( int ind2 = 1; ind2 <= m; ind2++) {
                
                if ( text1[ind1-1] == text2[ind2-1]) {
                   dp[ind1][ind2] = 1+ dp[ind1-1][ind2-1];
                } else {
                   dp[ind1][ind2] = max (dp[ind1-1][ind2], dp[ind1][ind2-1]);
                }
            }
        }

        return dp[n][m];
    }
};

//space optimization with tabulatons 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for ( int ind1 = 1; ind1 <= n; ind1++) {
            for ( int ind2 = 1; ind2 <= m; ind2++) {
                
                if ( text1[ind1-1] == text2[ind2-1]) {
                   curr[ind2] = 1+ prev[ind2-1];
                } else {
                   curr[ind2] = max (prev[ind2], curr[ind2-1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};



