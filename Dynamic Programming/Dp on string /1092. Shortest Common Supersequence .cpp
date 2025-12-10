class Solution {
public:
    string lcs (string &a, string &b) {
        int n = a.size(), m = b.size();

        vector <vector<int>> dp(n+1, vector<int> (m+1, 0));

        for ( int i = 1; i <= n; i++) {
            for ( int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max ( dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // printing the shortest common super sequence 

        int i = n, j = m;

        string ans = "";

        while ( i > 0 && j > 0) {
            if(a[i-1] == b[j-1]) {
                ans += a[i-1];
                i--;j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                ans += a[i-1];
                i--;
            } else {
                ans += b[j-1];
                j--;
            }
        }

        while ( i > 0) {
            ans += a[i-1]; 
            i--;
        }
        while ( j > 0)  {
            ans += b[j-1];
            j--;
        } 
        reverse (begin(ans), end (ans));
        
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        
        string ans = lcs (str1, str2);
        return ans;
    }
};
