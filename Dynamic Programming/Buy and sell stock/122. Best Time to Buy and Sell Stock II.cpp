//recursion + memoization 

class Solution {
public:
    vector <vector<int>> dp;
    int solve ( int idx, int buy, int n, vector<int>& prices) {
        if ( idx == n) {
            return 0;
        }

        int profit = 0;

        if ( dp[idx][buy] != -1) {
            return dp[idx][buy];
        }
        
        if (buy) {

            profit = max (-prices[idx] + solve (idx+1, 0, n, prices) ,
                             solve ( idx +1, 1, n, prices));

        } else {

            profit = max ( prices[idx] + solve ( idx+1,1,n, prices) ,
                            solve(idx+1, 0, n, prices));

        }

        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize(n, vector<int>(2,-1));

        return solve (0 ,1 , n, prices);
    }
};


//tabulation


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        dp[n][0] = 0;
        dp[n][1] = 0;


        for ( int idx = n-1; idx>=0; idx--) {
            for ( int buy = 0; buy <= 1; buy++) {
                int profit = 0;  
                if (buy) {
                    profit = max (-prices[idx] + dp[idx+1][0] , dp[idx+1][1]);
                } else {
                    profit = max ( prices[idx] + dp[idx+1][1] , dp[idx+1][0]);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

//tabulation with spcae optimization 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2,0), curr(2,0);


        ahead[0] = 0;
        ahead[1] = 0;


        for ( int idx = n-1; idx>=0; idx--) {
            for ( int buy = 0; buy <= 1; buy++) {
                int profit = 0;  
                if (buy) {
                    profit = max (-prices[idx] + ahead[0] , ahead[1]);
                } else {
                    profit = max ( prices[idx] + ahead[1] , ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};

//tabualation with variables 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int abuy, anbuy, currbuy = 0, currnbuy = 0;
        abuy = anbuy = 0;

        for ( int idx = n-1; idx>=0; idx--) {
            
            currbuy = max (-prices[idx] + anbuy , abuy);
            currnbuy = max ( prices[idx] + abuy , anbuy);    

            abuy = currbuy;
            anbuy = currnbuy;
        }
        return abuy;
    }
};
