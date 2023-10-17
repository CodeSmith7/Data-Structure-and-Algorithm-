#include <iostream>
#include<stack>

using namespace std;

//Insert at bottom function uses recursion 
void insertAtBottom(stack<int> &s,int x) {
  if (s.size() == 0) {
    s.push(x);
    return;
  }
  int ele = s.top();
  s.pop();
  insertAtBottom(s,x);
  s.push(ele);
}

//Reversing the stack
void reverseStack(stack<int> &s) {
  if (s.size() == 0) {
    return;
  }
  int ele = s.top();
  s.pop();
  reverseStack(s);

  insertAtBottom(s,ele);

}

int main() {
  stack<int> s;
  int ele;
  while (cin >> ele) {
    s.push(ele);
  }
  //reverseStack(s);
  insertAtBottom(s,1000);
  insertAtBottom(s,2000);
  cout << " Bef0ore Reversing the stcak " << endl;
  // while (!s.empty()) {
  //   cout << s.top() << endl;
  //   s.pop();
  // }
  reverseStack(s);
  cout << " After Reversing the stack" << endl;
  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
  return 0;
 
}