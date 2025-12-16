class Solution {
public:
    vector<vector<int>> dp;

    int solve ( int idx, int n, int buy, vector<int>& prices) {
        if ( idx >= n ) {
            return 0;
        }

        if ( dp[idx][ buy] != -1) {
            return dp[idx][buy];
        }

        if ( buy ) {
            return dp[idx][buy] = max ( -prices[idx] + solve ( idx +1, n,0, prices) , solve ( idx+1, n, 1, prices));
        } else {
            return dp[idx][buy] = max ( prices[idx] + solve ( idx + 2,n,1, prices ) , solve ( idx+1, n, 0, prices));

        }


    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize(n, vector<int>(2, -1));

        return solve ( 0,n,1,prices);
    }
};

//tabulation approach 
class Solution {
public:
    vector<vector<int>> dp;

    int solve ( int idx, int n, int buy, vector<int>& prices) {
        if ( idx >= n ) {
            return 0;
        }

        if ( dp[idx][ buy] != -1) {
            return dp[idx][buy];
        }

        if ( buy ) {
            return dp[idx][buy] = max ( -prices[idx] + solve ( idx +1, n,0, prices) , solve ( idx+1, n, 1, prices));
        } else {
            return dp[idx][buy] = max ( prices[idx] + solve ( idx + 2,n,1, prices ) , solve ( idx+1, n, 0, prices));

        }


    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize(n+2, vector<int>(2, 0));

        for ( int idx = n-1; idx >= 0; idx--) {
            for ( int buy = 0; buy <2; buy++) {

                if ( buy ) {
                    dp[idx][buy] = max ( -prices[idx] + dp[idx+1][0] , dp[idx+1][1]);
                } else {
                    dp[idx][buy] = max ( prices[idx] + dp[idx+2][1] , dp[idx+1][0]);
                }

            }
        }

        return dp[0][1];
    }
};
