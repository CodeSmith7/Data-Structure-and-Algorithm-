
//using the recursion and memoization
int solve (int idx, int last, vector<vector<int>> &points, vector<vector<int>>& dp) {
    if ( idx == 0 ) {
        int maxi = 0;
        for ( int i = 0; i <3; i++) {
            if (i != last) {
                maxi  = max (maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if (dp[idx][last] != -1) {
        return dp[idx][last];
    }

    int maxi = 0;

    for ( int i = 0; i < 3;  i++)  {
        if ( i!=last) {
            int ans = points[idx][i] + solve ( idx -1, i, points, dp);
            maxi = max (maxi, ans);
        }
    }
    return dp[idx][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    vector<vector<int>> dp(n+1, vector<int>(4,-1));

    return solve (n-1, 3 , points, dp);
}



//using tabulation 


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    vector<vector<int>> dp(n, vector<int>(4,0));

    dp[0][0] = max (points[0][1], points[0][2]);
    dp[0][1] = max ( points[0][0], points[0][2]);
    dp[0][2] = max ( points[0][1], points[0][0]);
    dp[0][3] = max (points[0][1], max (points[0][0], points[0][2]));

    for ( int day = 1; day < n; day++) {
        for ( int last = 0; last < 4; last++) {
            
            for ( int task = 0;task< 3; task++) {
                if (task != last ) {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max (dp[day][last], point);
                }
            }
        }
    }

    return dp[n-1][3];

}


//space optimization
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    vector<int> prev_dp(4,0);

    prev_dp[0] = max (points[0][1], points[0][2]);
    prev_dp[1] = max ( points[0][0], points[0][2]);
    prev_dp[2] = max ( points[0][1], points[0][0]);
    prev_dp[3] = max (points[0][1], max (points[0][0], points[0][2]));

    for ( int day = 1; day < n; day++) {
        vector<int> temp(4,0);
        for ( int last = 0; last < 4; last++) {
            temp[last] = 0;
            for ( int task = 0;task< 3; task++) {
                if (task != last ) {
                    temp[last] = max(temp[last],points[day][task] + prev_dp[task]);
                }
            }
        }
        prev_dp = temp;
    }

    return prev_dp[3];

}


