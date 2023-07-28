 #include <iostream>
 #include <climits>
 #include<bits/stdc++.h>
 using namespace std;

   int main()

 { int a[]= {1,2,3,4,5,6,7,8};

  //memset function (works only for 0and -1)
  memset(a,-1,sizeof(a));
    for(auto  x: a)
     cout<<x<<" ";
 // memset using charACTER
      char str[] = "geeksforgeeks";
    memset(str, 'a', sizeof(str));
    cout << str<<" ";

    int ab[10]={1};
    cout<<endl;
    for(auto x: ab)
    cout<<x<<" ";

    return 0;
} 