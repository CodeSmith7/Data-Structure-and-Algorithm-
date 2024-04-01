#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  string s = "Abhi  ruplai   ";
  
  int idx = s.find_last_not_of(' ') + 1;
  cout << s.size() << " " <<  idx << " " << s[idx]<< endl;
  s.erase(idx);
  int len = s.size();
  cout << "string is ->  " << s <<" " << s.size() << endl;

  int lastSpaceIdx = s.find_last_of(' ');

  cout << lastSpaceIdx << endl;

  cout << len -lastSpaceIdx - 1;


  return 0;
}
