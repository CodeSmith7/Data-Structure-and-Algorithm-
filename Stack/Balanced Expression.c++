#include <iostream.>
using namespace std;

void isBalanced(string &exp) {
  stack<char> st;
  for (auto x: exp) {
    if (st.size() == 0) {
      st.push(x);
    }
    else if ( (st.top() == '(' && x ==')') ||
               (st.top() == '{' && x =='}') ||
                (st.top() == '[' && x ==']') ) {
      st.pop();
    }
    else {
      st.push(x);
    }      
  }
  //checking the stack is empty or not if empty then valid else not valid 

  if (st.empty()) {
    cout << " Valid Expression " << endl;
  } else {
    cout << "Not Valid Expression " << endl;
  }
 
}

int main() {
  
   string exp = "{{{}}()()}[[[]]]";
   isBalanced(exp);
   return 0;
}
