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


//code for printing one subsequence (whose sum  == k)
bool printOneSub(int idx, vector<int>& nums,int s, vector <int>& sub, int sum) {
   if ( idx == nums.size()) {
      if ( s == sum ) {
         for (auto it : sub ) {
            cout << it << " ";
         }
         cout << endl;
         return true;
      } else {
         return false;
      }
   }
   s = s + nums[idx];

   sub.push_back(nums[idx]);

  if ( printOneSub(idx+1,nums, s, sub, sum) == true) {
   return true;
  } 

   s= s - nums[idx];
   sub.pop_back();

   if ( printOneSub(idx+1,nums, s, sub, sum) == true) {
      return true;
   } 

   return false;

   
}

