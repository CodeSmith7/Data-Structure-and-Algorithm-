#include<iostream>
#include<string>
#include<stack>

using namespace std;

string removeBackspace(string &s){
    int idx = 0;
    for (int i = 0; i < s.size();i++){
        if (s[i] != '?'){
            s[idx++] = s[i];
        }
        else if (s[i] == '?' && idx >= 0){
            idx--;
        }

        if (idx < 0) idx = 0;

    }
    return s.substr(0,idx);
}
string removeUsingStack(string &s){
 stack<char> c;
  int i = 0;
  for (auto x: s){
     if (x != '?'){
        c.push(x);
     } else {
         c.pop();
     }
    }
    
    while (!c.empty()){
        s[i++] = c.top();
        c.pop();
    }

   return s.substr(0,i);

  }

int main(){
    string a = "abjjnjnnn???????hi?a";
   // cout << removeBackspace(a) << endl;
    cout << removeUsingStack(a) << endl;
    return 1;

}