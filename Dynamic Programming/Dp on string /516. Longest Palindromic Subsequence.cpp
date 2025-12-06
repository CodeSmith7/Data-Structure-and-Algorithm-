class Solution {
public:
    vector <vector<int>> t;

    int lcs ( int idx1, int idx2, string a, string b) {

        if (idx1< 0 || idx2< 0) {
            return 0;
        }
        if (t[idx1][idx2] != -1) {
            return t[idx1][idx2];
        }

        if (a[idx1] == b [idx2]) {
            return 1 + lcs ( idx1-1, idx2 -1, a, b);
        }
        return t[idx1][idx2] = max ( lcs (idx1-1, idx2, a,b), lcs (idx1, idx2-1, a, b));

    }

    int lcs_tabulation(string a, string b) {
        int n = a.size();
        vector<vector<int>> dp (n+1, vector<int>(n+1, 0));

       
        for ( int i = 1; i <= n; i++) {
            for ( int j = 1; j <= n; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
    int lcs_tabulation_space_optimisation(string a, string b) {
        int n = a.size();

        vector <int> prev (n+1,0), curr(n+1, 0);


       
        for ( int i = 1; i <= n; i++) {
            for ( int j = 1; j <= n; j++) {
                if (a[i-1] == b[j-1]) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }
    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        t.resize(n,vector<int>(n, -1));
        //return lcs( n-1, n-1, temp, s);

        //return lcs_tabulation(temp, s);

        return lcs_tabulation_space_optimisation(temp, s);
    }
};
