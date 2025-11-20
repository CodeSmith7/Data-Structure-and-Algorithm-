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

        string s = "";

        int i = n, j = m;
        while ( i>0 && j > 0) {
            if(text1[i-1] == text2[j-1] ) {
                s += text1[i-1];
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(begin(s), end(s));
        cout << "LCS is : " << s << endl;

        

        return dp[n][m];
    }
};
