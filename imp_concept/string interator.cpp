#include <iostream>
#include <string>

using namespace std;

int main() {
  string s = "Abhishek";

  //string iterators  (container) 
  string::iterator it;
  string::reverse_iterator rit;
   for (it = s.begin();it != s.end();it++) {
    cout << *it << " "; 
   }
   cout << endl;
   for (rit = s.rbegin();rit != s.rend();rit++) {
    cout << *rit << " "; 
   }
   cout << endl << "aafter third iteration" << endl;
   //here end always goes to the ending +1 but begin only goes to the that thing that is defined 

   for (it = s.end()-1;it >= s.begin();it--) {
    cout << *it << " "; 
   }   
  return 0;
}
