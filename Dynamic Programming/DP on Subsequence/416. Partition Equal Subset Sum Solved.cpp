class Solution {
public:
    bool isSubsetSum (vector<int>& nums, int target ) {
        int n = nums.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1, false));

        for ( int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for ( int i = 1; i < n; i++) {
            for ( int j = 1; j <= target; j++) {
                bool nottake = dp[i-1][j];
                bool take = false;
                if ( nums[i] <= j) {
                    take = dp[i-1][j - nums[i]];
                }

                dp[i][j] = take || nottake;

            }
        }

        return dp[n-1][target];

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for( int &ele : nums) {
            sum += ele;
        }
        if ( sum &1) {
            return false;
        }
        return isSubsetSum (nums, sum/2);
    }
};


//space optimisation 
class Solution {
public:
    bool isSubsetSum (vector<int>& nums, int target ) {
        int n = nums.size();
        vector <bool> prev(target+1, 0), curr (target+1,0);

        prev[0] = curr[0] = true;

        for ( int i = 1; i < n; i++) {
            for ( int j = 1; j <= target; j++) {
                bool nottake = prev[j];
                bool take = false;
                if ( nums[i] <= j) {
                    take = prev[j- nums[i]];
                }

                curr[j] = take || nottake;

            }
            prev = curr;
        }

        return prev[target];

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for( int &ele : nums) {
            sum += ele;
        }
        if ( sum &1) {
            return false;
        }
        return isSubsetSum (nums, sum/2);
    }
};
