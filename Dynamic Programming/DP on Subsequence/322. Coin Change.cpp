//Recursion + memoization 
class Solution {
public:
    vector <vector<int>> dp;
    int solve (int idx, vector<int>& coins, int amount) {
        if (idx == 0) {
            if (amount % coins[idx] == 0) {
                return amount / coins[idx];
            } else {
                return 1e9;
            }
        }
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        int nottake = 0 + solve ( idx-1, coins, amount);
        int take  = INT_MAX;
        if (coins[idx] <= amount) {
            take = 1 + solve (idx, coins, amount - coins[idx]); //for infinite suppy index must not be decremented on take case 
        }
        return  dp[idx][amount] = min(take, nottake);
    }


    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n, vector<int>(amount+1, -1));
        int ans = solve (n-1, coins, amount);
        return ans >= 1e9 ? -1: ans;
    }
};


//tabulation 

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        //base case
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) {
                dp[0][t] = t / coins[0];
            } else {
                dp[0][t] = 1e9;
            }
        }

        for (int i = 1; i < n; i++) {
            for ( int t = 0; t <= amount; t++) {
                
                int nottake = 0 + dp[i-1][t];
                int take  = INT_MAX;
                if (coins[i] <= t) {
                    take = 1 + dp[i][t-coins[i]]; //for infinite suppy index must not be decremented on take case 
                }

                dp[i][t] = min(take, nottake);

            }
        }

        return dp[n-1][amount] >= 1e9 ? -1: dp[n-1][amount];
    }
};


//tabulation with space optimization 
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1, 0);

        //base case
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) {
                prev[t] = t / coins[0];
            } else {
                prev[t] = 1e9;
            }
        }

        for (int i = 1; i < n; i++) {
            for ( int t = 0; t <= amount; t++) {
                
                int nottake = 0 + prev[t];
                int take  = INT_MAX;
                if (coins[i] <= t) {
                    take = 1 + curr[t-coins[i]]; //for infinite suppy index must not be decremented on take case 
                }

                curr[t] = min(take, nottake);
            }
            prev = curr;
        }

        return prev[amount] >= 1e9 ? -1: prev[amount];
    }
};
