#include <iostream>
#include<vector>
using namespace std;
// just put the address of operator in function definition
void vector_update(vector<vector<int> >& b){
   for (int i=0;i<b.size();i++){
     for(int j=0;j<b[i].size();j++){
       b[i][j] = b[i][j] * 2;
     }
    }
    cout << "FUNCTION: " << endl;
    for(auto x:b){
      for(auto y:x){
        cout<<y<<"\t";
      }
      cout << endl;
    }

  }  


int main() {
  vector<vector<int> > a={
    {1,2},
    {4,5,6,11,3,6,7,8,},
    {7,8,9,7,9},
    {1,6,4}
  };
  vector_update(a);
  
  //ITERATOR
   cout << "MAIN: " << endl;
  for (auto x:a){
    for(auto y:x)
    cout<<y<<"\t";
    cout<<endl;
  }
  return 0;
}