class Solution {
  public:
    int countNumberOfSubset(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<int>> t(n+1,vector<int>(sum+1, 0));
        
        //Initialisation 
        for ( int i = 0; i < n+1; i++) {
            t[i][0] = 1;
        }
        
        for ( int i = 1; i < n+1; i++) {
            for ( int j = 0; j <sum +1; j++ ) {
                if ( arr[i-1] <= j) {
                    t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][sum];
        
        
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum  = 0;
        
        for ( int &ele : arr) {
            sum += ele;
        }
        
        if ( (d + sum) % 2 != 0) return 0;
        if (d > sum) return 0;
        
        int newSum = (d + sum ) / 2;
        
        return countNumberOfSubset(arr, newSum);
    }
};
