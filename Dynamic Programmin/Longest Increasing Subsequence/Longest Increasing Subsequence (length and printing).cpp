//memoization

class Solution {
public:
    vector<vector<int>> dp;
    int solve ( int idx, int prev_idx, int n,  vector<int>& nums) {
        if ( idx ==  n) return 0;

        if ( dp[idx][prev_idx+1] != -1) {
            return dp[idx][prev_idx+1];
        }

        int len = solve ( idx+1, prev_idx, n, nums);
        if ( prev_idx == -1 || nums[idx ] > nums[prev_idx]) {
            len = max ( len, 1 + solve ( idx+1, idx, n, nums));
        }

        return dp[idx][prev_idx+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        dp.resize(n, vector<int>(n+1, -1));
        return solve ( 0, -1,n,  nums);
    }
};


//tabulation

class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int idx = n-1; idx >= 0; idx--) {
            for ( int prev_idx = idx -1; prev_idx >= -1;prev_idx--) {
                
                int len = dp[idx+1][prev_idx+1];

                if ( prev_idx == -1 || nums[idx ] > nums[prev_idx]) {
                    len = max ( len, 1 + dp[idx+1][idx+1]);
                }

                dp[idx][prev_idx+1] = len;
            }
        }

        for (int i = 0; i <= n; i++) {
            for ( int j = 0; j<= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }


 
        return dp[0][0];
        
    }
};


//space optimization
class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> ahead(n+1, 0), curr(n+1, 0);



        for (int idx = n-1; idx >= 0; idx--) {
            for ( int prev_idx = idx -1; prev_idx >= -1;prev_idx--) {
                
                int len = ahead[prev_idx+1];

                if ( prev_idx == -1 || nums[idx ] > nums[prev_idx]) {
                    len = max ( len, 1 + ahead[idx+1]);
                }

                curr[prev_idx+1] = len;
            }
            ahead = curr;
        }

 
        return ahead[0];
        
    }
};


//single array pass 

class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1), hash(n); // initialise with 1 

        int maxi = 1;
        int lastidx = 0;
        for ( int idx = 0; idx < n; idx++) {
            hash[idx] = idx;
            for ( int prev = 0; prev < idx; prev++) {
                if ( nums[prev] < nums[idx] && 1+ dp[prev ] > dp[idx]) {
                    dp[idx] =  1+ dp[prev];
                    hash[idx] = prev;
                }
            }

            if ( dp[idx] > maxi) {
                maxi = dp[idx];
                lastidx = idx;
            } 
        }

        vector<int> lis;
        lis.push_back(nums[lastidx]);
        while ( lastidx != hash[lastidx]) {
            lastidx = hash[lastidx];
            lis.push_back(nums[lastidx]);
        }

        reverse ( begin( lis), end (lis));

        for ( auto it: lis) {
            cout << it << " ";
        }
        cout << endl;

        return maxi; 
        
    }
};
