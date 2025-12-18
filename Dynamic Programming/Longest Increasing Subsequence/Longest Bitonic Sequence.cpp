int longestBitonicSubsequence(vector<int>& nums, int n)
{
	// Write your code here.

	

        vector<int> dp1(n,1); // initialise with 1 

        vector<int> dp2(n,1);

        int maxi = 0;

        
        for ( int idx = 0; idx < n; idx++) {
            for ( int prev = 0; prev < idx; prev++) {
                if ( nums[idx] > nums[prev] && 1+ dp1[prev] > dp1[idx]) {
                    dp1[idx] =  1+ dp1[prev];
                }
            }
             
        }

		for (int idx = n - 1; idx >= 0; idx--) {
        for (int next = n - 1; next > idx; next--) {
            if (nums[idx] > nums[next] && 1 + dp2[next] > dp2[idx]) {
                dp2[idx] = 1 + dp2[next];
            }
        }
}


		for ( int i = 0; i < n; i++) {
			maxi = max ( maxi, dp1[i] + dp2[i] -1);
		}
	
    return maxi;
}
