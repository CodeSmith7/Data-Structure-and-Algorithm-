#include<iostream>
using namespace std;

int solve (int dividend,int divisor){
    int s = 0;
    int e = abs(dividend);
    int ans = 0;
    while (s <= e){
        int mid = s +(e-s)/2;

        //perfect solution
        if(abs(mid * divisor) == abs(dividend)){
            ans = mid;
            break;
        }
        //not perfect solution 
        if (abs(mid * divisor) > abs(dividend)){
            //left
            e = mid -1;
        }
        else{
            //ans store
            ans = mid;
            // right search
            s= mid + 1;
        }
    }
    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)){
        return ans;
    }
    else {
        return -ans;
    }
}

int main(){

    int dividend = -22;
    int divisor = 7;
    cout << "quotient is -> " << solve(dividend,divisor) << endl;


}