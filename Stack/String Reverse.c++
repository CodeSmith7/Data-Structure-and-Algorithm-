#include <iostream>
#include<stack>

using namespace std;

int main() {
  stack<char> c;
  string s ="abhishekbhadauriyaisAgreatmanandhe",m="";
  for (auto x:s){
    c.push(x);
    cout<<x<<" ";
  }

  cout << c.size() << endl;

  while (!c.empty()){
    cout<<c.top()<<" ";
    m = m+c.top();
    c.pop();
  }
cout << endl;
  cout<<"reverse is :"<< m;
  return 0;
}
