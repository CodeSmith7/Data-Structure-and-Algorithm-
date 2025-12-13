//recursion + memoization (0 based indexing )
class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &text, string &pattern) {
        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;

        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++)
                if (pattern[k] != '*') return false;
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (text[i] == pattern[j] || pattern[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, text, pattern);

        if (pattern[j] == '*')
            return dp[i][j] = solve(i - 1, j, text, pattern) || solve(i, j - 1, text, pattern);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.resize(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, p);
    }
};


//meoization 1 based index ing 
class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &text, string &pattern) {
        if (i == 0 && j == 0) return true;
        if (j == 0 && i > 0) return false;

        if (i == 0 && j > 0) {
            for (int k = 1; k <= j; k++)
                if (pattern[k-1] != '*') return false;
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (text[i-1] == pattern[j-1] || pattern[j-1] == '?')
            return dp[i][j] = solve(i - 1, j - 1, text, pattern);

        if (pattern[j-1] == '*')
            return dp[i][j] = solve(i - 1, j, text, pattern) || solve(i, j - 1, text, pattern);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(n, m, s, p);
    }
};


//tabulation 
class Solution {
public:

    bool isMatch(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
         
        //base cases

        dp[0][0] = true;
        
        for ( int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        for ( int j = 1; j <= m; j++) {
            int flag = true;
            for (int k = 1; k <= j; k++) {
                if (pattern[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        //changing parameters

        for ( int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];

                else if (pattern[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];

                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};


//space optimised tabulation 

class Solution {
public:

    bool isMatch(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        vector<bool> prev(m+1,false), curr(m+1, false);
         
        //base cases

        prev[0] = true;

        for ( int j = 1; j <= m; j++) {
            int flag = true;
            for (int k = 1; k <= j; k++) {
                if (pattern[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        //changing parameters

        for ( int i = 1; i <= n; i++) {
            curr[0] = false;
            for (int j = 1; j <= m; j++) {
                if (text[i-1] == pattern[j-1] || pattern[j-1] == '?')
                    curr[j] = prev[j-1];

                else if (pattern[j-1] == '*')
                    curr[j] = prev[j] || curr[j-1];

                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};
