#include <iostream>
#include<vector>
#include<string.h>
using namespace std;
  void printSubsequence(string str,string op,int i,vector<string>& v){
    if(i>= str.length()){
      //cout<< op <<endl;
      v.push_back(op);
      return ;
    }
    //exclude
    printSubsequence(str,op+str[i],i+1,v);
    //include
     printSubsequence(str,op,i+1,v);
  }

int main() {
string str = "ABC";
string op ="";
vector<string> v;
int i=0;
cout << "The subsequence of" << str <<"are as follows :-" << endl;
printSubsequence(str,op,i,v);
for(auto x:v)
cout<<x<<endl;

cout << "length of vector is : " <<  v.size();
  return 0;
}