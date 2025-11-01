void printSub ( int idx, vector<int>& nums, vector <int>& sub) {
   if ( idx >= nums.size()) {
      for ( int &ele: sub) {
         cout << ele << " ";
      }
      cout << endl;
      return;
   }

   sub.push_back(nums[idx]);
   printSub(idx+1,nums, sub);
   sub.pop_back();
   printSub(idx+1,nums,sub);
}

void solve(){
    
   vector <int> nums = {4,7,9,10};

   vector<int> sub;

   printSub(0, nums, sub);
}
