 #include <iostream>
 #include <climits>
 #include<bits/stdc++.h>
 using namespace std;

   int main()
 {
     int n ,r;
  cout<<"enter the number to rotate \n";
  cin>>n;
  cout<<"enter the rotate number";
  cin>>r;
  // calculation of number of digit  

    int digit =  (int)(log10(n) + 1);
    cout<<digit<<endl;
    //if rotatioon is greater than number of digit 
    r = r%digit;
   // if rotation is in negative direction 
         if (r<0)
         r = r+digit;
    int div=1,mul=1;
 
    for(int i=1;i <= digit;i++)
    {
       if(i <= r)
        div *=10;
       else                                                                                                                         
        mul *= 10;
    }
   //  cout<< mul <<" "<< div<<endl;



  int q = n/div;    //quotient 
  int rem = n%div;  //remainder 

  //calculation of rotated number 

  int rotate = rem*mul + q;

 cout<<endl<<"Rotated number is :- "<<rotate ;


      return 0;
} 