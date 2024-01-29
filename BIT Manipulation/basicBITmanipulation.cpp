#include <iostream>
#include <bitset>
using namespace std;

string getBinary(int x ) {
  bitset<8> b(x);
  return b.to_string();
}
int main() {
  cout << getBinary (255) << endl;
  int num = 15;

  // arr[curr] = 1;
  // int mask = 0;
  // mask =  mask | ( 1 << curr) 
  for (int b = 0 ; b < 32; b++) {
    if (num & (1<<b)) { //check the bit is set or not using &
      int res = num^(1<<b); //unset the bit using XOR
    }
    else {
      int res2= num | (1<<b); //set the bit using OR
    }
  }
  return 0;
}
