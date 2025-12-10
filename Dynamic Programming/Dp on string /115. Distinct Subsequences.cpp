class Solution {
public:
    vector<vector<int>> dp;
    int solve ( int i, int j, string& s, string& t) {
        if ( j < 0) return 1;
        if ( i < 0) return 0;

        if ( dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == t[j]) {
            return  dp[i][j] = solve ( i-1, j-1, s, t) + solve (i-1, j, s,t);
        } else {
            return  dp[i][j] = solve(i-1, j, s, t);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.resize(n, vector<int>(m, -1));

        return solve (n-1,m-1, s, t);
    }
};

//using tabulation 
class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(m+1, 0));

        for ( int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for ( int i = 1; i <= n; i++) {
            for ( int j = 1; j<= m; j++) {
                if (s[i-1] == t[j-1] ) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }

};


//using space optimisation 

class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned int> prev(m+1,0), curr(m+1, 0);

        prev[0] = 1;
        curr[0] = 1;

        for ( int i = 1; i <= n; i++) {
            
            for ( int j = 1; j<= m; j++) {
                if (s[i-1] == t[j-1] ) {
                    curr[j] = prev[j-1] + prev[j];
                } else {
                    curr[j]= prev[j];
                }
            }
            prev = curr;
        }

        return prev[m];
    }

};

//using one d array optimisation 
class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned int> dp(m+1,0);

        dp[0] = 1;

        for ( int i = 1; i <= n; i++) {
            for ( int j = m; j>=1 ; j--) {
                if (s[i-1] == t[j-1] ) {
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }

        return dp[m];
    }

};
