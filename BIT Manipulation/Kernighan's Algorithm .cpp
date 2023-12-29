#include <iostream>
using namespace std;
//Kernighan's Algorithm -> count number of set bits efficiently 
int main() {
  //107 ->  5 set bit
  //57  -> 4 set bit 
  int n = 107;
  int count = 0;
  while (n != 0) {
    int rsbm = n & -n;
    n -= rsbm;
    count++;
  }
  cout << "number of set bits are ->  " << count << endl;
  return 0;
}
