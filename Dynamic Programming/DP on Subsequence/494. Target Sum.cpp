class Solution {
public:
    const int MOD = 1e9+7;
        
    int countPartitions(int n, int d, vector<int> &arr) {
        // Write your code here.

        int totsum = 0;

        for ( int &ele : arr) {
            totsum += ele;
        }
        if (d > totsum) return 0;
        if ((totsum - d) %2 != 0) return 0;

        int s = (totsum - d)/2;



        vector <int> prev (s+1, 0), curr(s+1, 0);

        if (arr[0] == 0) {
            prev[0] = 2;
        } else {
            prev[0] = 1;
        }

        if(arr[0]!=0 && arr[0] <= s) prev[arr[0]] = 1;


        for ( int i = 1; i < n;i++)  {
            for (int sum = 0; sum <= s; sum++ ) {
                int nottake = prev[sum];
                int take = 0; 
                if (arr[i] <= sum) {
                    take = prev[sum -arr[i]];
                }

                curr[sum] = (take + nottake) % MOD;
            }
            prev = curr;
        }

        return prev[s];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};

//this is question is same the find the subsets with given difference .
