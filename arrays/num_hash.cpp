#include<bits/stdc++.h>
using namespace std;
//globally everything will be initialize with zero 
//int  hashh[13];
int main()
{      // NUMBER HASHING  
    int n;
    cout<<"enter the size of array "<<endl;
    cin >>  n;
    int arr[n];
    for (int i=0;i<n;i++)
        cin >> arr[i];

    
    //precompute 
    //map always store ht value in sorted manner  
    map<int,int> m;
      for (int i=0;i<n;i++)
        m[arr[i]]++;

     cout<<" mapping in the hash map \n "<<endl;
     //iterating in the map 
     
    for(auto x:m)
    cout<<x.first<<"--> "<<x.second<<endl;    

    int q;
    cin>>q;
    while(q--)
    {
      int number ;
      cin >> number;
      //fetch
      cout << m[number]<<endl;
    }


    return 0;
}