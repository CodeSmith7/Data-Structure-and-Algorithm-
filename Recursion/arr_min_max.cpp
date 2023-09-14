#include<iostream>
#include<climits>
using namespace std;
//recursive function for finding maximum element
void getMax(int a[],int n,int i,int& m){
    //Base case
    if(i>=n){
        return;
    }
    //process
    if(a[i]>m){
        m = a[i];
    }
    //recursive relation
    getMax(a,n,i+1,m);

}
//recursive function for finding minimum element 
void getMin(int a[],int n,int i,int& m){
    //Base case
    if(i>=n){
        return;
    }
    //process
    if(a[i]<m){
        m = a[i];
    }
    //recursive relation
    getMin(a,n,i+1,m);

}

int main(){

    int a[]={10,34,77,98,12,7,90,127};
    int minimum = INT_MAX;
    int maximum  = INT_MIN;
    int i=0,n=8;
    getMin(a,n,i,minimum);
    getMax(a,n,i,maximum);
    
    cout<<" Maximum element is : "<< maximum <<endl;
    
    cout<<" Minimum element is : "<< minimum <<endl;
}