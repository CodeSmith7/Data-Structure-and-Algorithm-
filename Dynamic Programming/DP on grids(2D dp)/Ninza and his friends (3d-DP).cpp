// class Solution {
// public:
//     vector<vector<vector<int>>> t;
//     int solve (int i ,int j1, int j2,vector<vector<int>>& g,int n, int m ) {

//         if ( j1 < 0 || j1 >= m || j2< 0 || j2 >= m) {
//             return -1e8;
//         }

//         if ( i == n-1) {
//             if ( j1 == j2 ) {
//                 return g[i][j1];
//             } else {
//                 return g[i][j1] + g[i][j2];
//             }
//         }

//         if ( t[i][j1][j2] != -1) {
//             return t[i][j1][j2];
//         }

//         //explore all the pathds 

//         int maxi = 0;

//         for ( int dj1 = -1; dj1 <= 1; dj1++) {
//             for ( int dj2 = -1; dj2 <= 1; dj2++) {
//                 if (j1 == j2) {
//                     maxi = max (maxi, g[i][j1] + solve ( i+1, j1 + dj1 , j2 + dj2, g, n, m));
//                 } else {
//                     maxi = max(maxi, g[i][j1] + g[i][j2] +solve ( i+1, j1 + dj1 , j2 + dj2, g, n, m));
//                 }
//             }
//         }

//         return t[i][j1][j2] = maxi;
        
//     }
//     int maxChocolates(vector<vector<int>>& g) {
//         int n = g.size(); 
//         int m = g[0].size();

//         t.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));

//         return solve (0,0,m-1, g, n, m);
//     }
// };


//tabulation 
class Solution {
public:
    int maxChocolates(vector<vector<int>>& g) {
        int n = g.size(); 
        int m = g[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>( m, vector<int>(m,0)));

        //base case 
        for ( int j1 = 0; j1<m; j1++) {
            for ( int j2 = 0; j2 < m; j2++) {
                if ( j1  == j2 ) dp[n-1][j1][j2] = g[n-1][j1];
                else dp[n-1][j1][j2] = g[n-1][j1] + g[n-1][j2];
            }
        }

        int maxi = -1e8;

        //explore every state 
        for ( int i = n-2; i >= 0; i--) {
            for ( int j1 = 0; j1 < m; j1++) {
                for ( int j2 = 0; j2 < m; j2++) {
                    
                    int maxi = -1e8;

                    for ( int dj1 = -1; dj1 <= 1; dj1++) {
                        for ( int dj2 = -1; dj2 <= 1; dj2++) {

                            int value = 0;
                            if (j1 == j2) {
                                value = g[i][j1];
                            } else {
                                value = g[i][j1] + g[i][j2];
                            }

                            if ( j1 + dj1 >= 0 j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 <m) {
                                value += dp[i+1][j1+dj1][j2 + dj2];
                            } else {
                                value += -1e8; 
                            }

                            maxi = max (maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }


        return dp[0][0][ m-1];


        
    }
};
