#include<iostream>
using namespace std;
int main()
{  //uses to find maximum sub array sum 
    int a[]={ -2,1,-3,4,-1,2,1,-5,4};
    for(auto x: a)
    cout<<x<<" ";
    int sum=0,maxi=a[0],i=0;
    while(i<8)
    {    //step 1
        sum=sum+a[i];
        
        //step 2
        maxi=max(maxi,sum);
       //step 3
        if(sum<0)
        sum = 0;
        i++;
    }
    cout<<"\nMaximum of of elements of sub array is - "<<maxi;
}