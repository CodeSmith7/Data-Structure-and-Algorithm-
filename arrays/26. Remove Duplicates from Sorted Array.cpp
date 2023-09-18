class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int idx = 0;
       int n = nums.size();
       for (int i = 1;i<n;i++) {
           if (nums[i] != nums[idx]) {
               swap(nums[i],nums[idx+1]);
               idx++;
           }
       } 
       return  idx+1;
    }
};


//intution is : create another index idx and iterate it on array and increse idx only when new element found 
