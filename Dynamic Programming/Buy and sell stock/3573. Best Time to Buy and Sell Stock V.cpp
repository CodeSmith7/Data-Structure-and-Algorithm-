//memoization 
class Solution {
public:
    long long solve ( int i, int k, int CASE, int n,  vector<int>& prices, vector<vector<vector<long long>>>& dp) {

        if ( i >= n) {
            if ( CASE == 0) return 0;
            return INT_MIN;
        }

        if (dp[i][k][CASE] != -1) {
            return dp[i][k][CASE];
        }

        long long notTake = solve ( i+1, k, CASE, n, prices, dp);

        long long take = 0;
        
        if ( k > 0) {

            if ( CASE == 1) { // selling (normal)

                take = prices[i] + solve ( i+1, k-1, 0, n, prices, dp);

            } else if ( CASE == 2) { // buy back (short)
                take = -prices[i] + solve ( i+1, k-1, 0, n, prices, dp);

            } else {
                take = max ( prices[i] + solve ( i+1, k, 2, n, prices, dp),
                             -prices[i] + solve ( i+1, k, 1, n, prices, dp));

            }
        } 

        return  dp[i][k][CASE] = max ( take, notTake);
        
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();


        vector<vector<vector<long long>>> dp (n, vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        

        return solve (0, k, 0, prices.size(), prices, dp);
        
    }
};


//tabulationn
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int K) {
        int n = prices.size();
        
        static long long   t[1001][501][3];

        //base casre 
        for ( int k = 0; k <= K; k++) {
            t[n][k][0] = 0;
            t[n][k][1] = INT_MIN;
            t[n][k][2] = INT_MIN;
        }

        //filling the table 

        for ( int i = n-1; i>= 0; i--) {
            for ( int k = 0; k <= K; k++)  {
                //not take
                t[i][k][0] = t[i+1][k][0];

                t[i][k][1] = t[i+1][k][1]; //holding long

                t[i][k][2] = t[i+1][k][2]; // holding short



                //take
                if ( k > 0) {
                    //case 0
                    t[i][k][0] = max ( {t[i][k][0],prices[i] + t[i+1][k][2], -prices[i] + t[i+1][k][1] } );

                    //case 1
                    t[i][k][1] = max (t[i][k][1], prices[i] + t[i+1][k-1][0]);

                    //case2 
                    t[i][k][2] = max (t[i][k][2], -prices[i] + t[i+1][k-1][0]);
                }
            }
        }

        return t[0][K][0];
    }
};
