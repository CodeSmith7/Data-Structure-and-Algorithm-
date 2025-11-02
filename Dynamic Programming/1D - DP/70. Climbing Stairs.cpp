// class Solution {
// public:

//     int solve ( int n , vector<int>& t) {
//         if ( n <= 1) {
//             return 1;
//         }
//         if ( t[n] != -1) {
//             return t[n];
//         }

//         return t[n] = solve (n-1,t) + solve (n-2,t);
//     }
//     int climbStairs(int n) {

//         vector<int> t(n+1,-1);

//         return solve (n,t);

//     }
// };



//tabulation 
class Solution {
public: 

    int climbStairs(int n) {

       int prev = 1;
       int prev2 = 1;
        // remember here n == 0 give 1 so prev2 = 1
       for ( int i = 2; i < n+1;i++) {
        int temp = prev + prev2;
        prev2 = prev;
        prev = temp;
       }

       return prev;

    }
};
