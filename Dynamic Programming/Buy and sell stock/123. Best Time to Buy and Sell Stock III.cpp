//memoization
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve ( int idx, int n, int buy, int cap, vector<int>& prices) {
        if ( idx == n) return 0;
        if ( cap == 0) return 0;

        if ( dp[idx][buy][cap] != -1) {
            return dp[idx][buy][cap];
        }

        if ( buy ) {
            return dp[idx][buy][cap] = max (-prices[idx] + solve (idx+1, n, 0, cap, prices), 
                            solve (idx+1, n, 1, cap, prices) );
        } else {
            return dp[idx][buy][cap] = max ( prices[idx] + solve (idx+1, n, 1, cap -1, prices),
                                solve (idx+1, n, 0, cap, prices));
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));


        return solve (0, n,  1, 2, prices);
    }
};


//tabulation 
class Solution {
public:
    vector<vector<vector<int>>> dp;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        //base cases



        for ( int idx = n-1; idx>= 0; idx-- ) {
            for ( int buy = 0; buy < 2; buy++) {
                for ( int cap = 1; cap <= 2; cap++ ) {
                    if ( buy ) {
                        dp[idx][buy][cap] = max (-prices[idx] + dp[idx+1][0][cap], 
                                        dp[idx+1][1][cap] );
                    } else {
                        dp[idx][buy][cap] = max ( prices[idx] + dp[idx+1][1][cap-1],
                                            dp[idx+1][0][cap]);
                    }
                }
            }
        }
 

        return dp[0][1][2];
    }
};

//space optimization 
class Solution {
public:
    vector<vector<vector<int>>> dp;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0)) ;
    

        //base cases
        for ( int idx = n-1; idx>= 0; idx-- ) {
            for ( int buy = 0; buy < 2; buy++) {
                for ( int cap = 1; cap <= 2; cap++ ) {
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

        return after[1][2];
    }
};


//another way of doing it 

class Solution {
public:
    vector<vector<int>> dp;
    int solve ( int idx, int trans, int n, vector<int>& prices) {
        if ( idx == n || trans == 4) {
            return 0;
        }

        if ( dp[idx][trans] != -1) {
            return dp[idx][trans];
        }

        if ( trans % 2 == 0) { // buy
            return dp[idx][trans] = max(-prices[idx] + solve ( idx+1, trans +1, n, prices) ,
                                                solve( idx +1, trans, n, prices));
        } else { //sell
            return  dp[idx][trans] = max( prices[idx] + solve(idx+1, trans+1, n, prices) , 
                                            solve ( idx +1, trans, n, prices));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize( n, vector<int>(4, -1));


        return solve (0, 0, n, prices); 
    }
};


//using tabulation
class Solution {
public:
    vector<vector<int>> dp;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize( n +1, vector<int>(5, 0));

        for ( int idx = n-1; idx>=0; idx--) {
            for ( int trans = 0; trans < 4; trans++) {

                if ( trans % 2 == 0) { // buy
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

//using tabilation withb space optimization
class Solution {
public:
    vector<vector<int>> dp;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> curr(5,0), ahead(5,0);

        for ( int idx = n-1; idx>=0; idx--) {
            for ( int trans = 0; trans < 4; trans++) {

                if ( trans % 2 == 0) { // buy
                    curr[trans] = max(-prices[idx] + ahead[trans +1] ,
                                                        ahead[trans]);
                } else { //sell
                    curr[trans] = max( prices[idx] + ahead[trans+1], 
                                                    ahead[trans]);
                }

                ahead = curr;

            }
        }


        return ahead[0]; 
    }
};
