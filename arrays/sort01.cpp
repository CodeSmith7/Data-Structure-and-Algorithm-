#include<iostream>
#include<array>
using namespace std;
int main(){
       int a[]={1,1,1,1,0,0,1,0,1,0};
       int i=0,j=9;
     int s=0;
    while(i<=j){
        s++;
        if(a[i] == 0)
        i++;
        if(a[j] == 1)
        j--;
        if(a[i]==1 && a[j] == 0)
        swap(a[i],a[j]);
        for(int i : a){
       cout<<i<<"  ";
        }
        cout<<endl;
           
    }
      cout<<s<<endl; 

       for(auto x: a)
       cout<<x<<"  ";


 return 0;
}