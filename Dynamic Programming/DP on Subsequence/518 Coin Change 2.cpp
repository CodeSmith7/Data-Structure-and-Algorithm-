class Solution {
public:
    vector<vector<int>> dp;
    int solve ( int ind, vector<int>& coins, int tar ) {
        if ( ind == 0) {
            return tar % coins[0] == 0;
        }
        if (dp[ind][tar] != -1) {
            return dp[ind][tar];
        }

        int nottake = solve (ind -1, coins, tar );
        int take = 0; 
        if ( coins[ind] <= tar) {
            take = solve ( ind, coins, tar - coins[ind] );
        }
        return dp[ind][tar] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n, vector<int>(amount+1,-1));
        return solve (n-1, coins, amount);
    }
};


//using tabulation 
class Solution {
    const int MOD = 1e9+7;
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<unsigned long long>> dp(n, vector< unsigned long long>(amount+1,0));

        //base case
        for ( int tar = 0; tar <= amount; tar++) {
            dp[0][tar] = tar % coins[0] == 0;
        }

        for ( int i = 1; i < n; i++) {
            for ( int tar = 0; tar <= amount; tar++) {
                unsigned long long nottake = dp[i-1][tar];
                unsigned long long take = 0; 
                if ( coins[i] <= tar) {
                    take = dp[i][tar - coins[i]];
                }
                dp[i][tar] = (take + nottake);
            }
        }

        return dp[n-1][amount];
    }
};


//space optimization usind two vector 
class Solution {

public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<unsigned long long> prev (amount+1, 0), curr( amount+1, 0);

        //base case
        for ( int tar = 0; tar <= amount; tar++) {
            prev[tar] = tar % coins[0] == 0;
        }

        for ( int i = 1; i < n; i++) {
            for ( int tar = 0; tar <= amount; tar++) {
                unsigned long long nottake = prev[tar];
                unsigned long long take = 0; 
                if ( coins[i] <= tar) {
                    take = curr[tar - coins[i]];
                }
                curr[tar] = (take + nottake);
            }
            prev = curr;
        }

        return prev[amount];
    }
};


//using 1 - D array

