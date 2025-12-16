class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int abuy, anbuy, currbuy = 0, currnbuy = 0;
        abuy = anbuy = 0;

        for ( int idx = n-1; idx>=0; idx--) {
            
            currbuy = max (-prices[idx]  + anbuy , abuy); //upfront fee deduct fee here 
            currnbuy = max ( prices[idx] - fee + abuy , anbuy);    // for paying later deduct here

            abuy = currbuy;
            anbuy = currnbuy;
        }
        return abuy;
    }
};
