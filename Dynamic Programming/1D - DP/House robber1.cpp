//Approach 1 : recursion +. memoization 

class Solution {
public:
    vector<int> t;
    int solve ( int idx, vector<int>& nums) {
        if (idx == 0) return nums[idx];
        if ( idx < 0) return 0;

        if ( t[idx] != -1) {
            return t[idx];
        }

        int take = nums[idx] + solve(idx-2, nums);
        int nottake = solve(idx-1, nums);

        return t[idx] = max (take, nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        t.resize(n+1,-1);
        return solve (n-1,nums);
    }
};


//Approach 2 : using tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n,0);

        t[0] = nums[0];

        for ( int i= 1; i < n; i++) {
            int take  = nums[i];
            if ( i > 1) {
                take += t[i-2];
            }
            int nottake  = t[i-1];
            t[i] = max( take , nottake);
        }

        return t[n-1];
    }
};

//space optimization 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n,0);
        int prev = nums[0];
        int prev2 = 0;

        for ( int i= 1; i < n; i++) {
            int take  = nums[i];
            if ( i > 1) {
                take += prev2;
            }
            int nottake  = prev;
            int curr = max( take , nottake);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
