#include <iostream>
using namespace std;

void dfs(int i,int n){
  if(i>n){
    return;
  }
  cout << i << endl;
  for (int j= 0;j<10;j++){
    dfs(10*i+j,n);
  }
  
}
int main() {
  int n=100;
  for (int i=1;i<10;i++){
    dfs(i,n);
  }
  return 0;
}