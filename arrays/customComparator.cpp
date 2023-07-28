#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool cmp (char x,char y){
  return x>y;
}

int main() {
  int j = 0,i=0;
  string s = "121313abhishek";
  while (s[i] == ' ')
  i++;
  while (s[i]!='\0'){
    cout<< s[i++] << " ";

  }
  char a[10]="ABHISHEK";
  // for (int i =0;i<s.size();i++){
  //   cout << s[i] << "  " ;
  //     }
    cout << "charcter array"<<endl;
  while (a[j]!='\0'){

    cout << a[j++] << "  " ;
  } 

  cout << s << endl ;
  sort(s.begin(),s.end());
  cout << "after sorting ascending  order ->>  " << s<< endl;

  sort(s.begin(),s.end(),cmp);
  cout << "after sorting descending order ->>  " << s<< endl;

  vector<int> v{4,2,5,7,1,78};
  sort(v.begin(),v.end(),cmp);
  for (auto x: v){
    cout << x << " ";
  }
  cout << endl ;

  
  return 0;
}