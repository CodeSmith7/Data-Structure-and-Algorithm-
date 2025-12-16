class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> after(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0)) ;
    

        //base cases
        for ( int idx = n-1; idx>= 0; idx-- ) {
            for ( int buy = 0; buy < 2; buy++) {
                for ( int cap = 1; cap <= k; cap++ ) {
                    if ( buy ) {
                        curr[buy][cap] = max (-prices[idx] + after[0][cap], 
                                        after[1][cap] );
                    } else {
                        curr[buy][cap] = max ( prices[idx] + after[1][cap-1],
                                            after[0][cap]);
                    }
                }
                after = curr;
            }
        }

        return after[1][k];

    }
};


//seconf method tabulation 

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>  dp( n +1, vector<int>(2*k +1, 0));

        for ( int idx = n-1; idx>=0; idx--) {
            for ( int trans = 0; trans < 2*k; trans++) {

                if ( trans % 2 ==   0) { // buy
                    dp[idx][trans] = max(-prices[idx] + dp[idx+1][trans +1] ,
                                                        dp[idx +1][trans]);
                } else { //sell
                    dp[idx][trans] = max( prices[idx] + dp[idx+1][trans+1], 
                                                    dp[idx +1][trans]);
                }

            }
        }


        return dp[0][0]; 

    }
};


//second method space optimisation 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead(2*k+1, 0), curr(2*k+1, 0);

        for ( int idx = n-1; idx>=0; idx--) {
            for ( int trans = 0; trans < 2*k; trans++) {

                if ( trans % 2 ==   0) { // buy
                    curr[trans] = max(-prices[idx] + ahead[trans +1] ,
                                                        ahead[trans]);
                } else { //sell
                    curr[trans] = max( prices[idx] + ahead[trans+1], 
                                                    ahead[trans]);
                }

            }
            ahead = curr;
        }


        return ahead[0]; 

    }
};







