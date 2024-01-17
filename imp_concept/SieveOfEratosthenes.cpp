#include <iostream>
#include <vector>
using namespace std;

int main() {
  int size = 120;
  int c = 0;
  vector<bool> sieve(size,1);
  sieve[0] = sieve[1] = 0;
  for (int i = 2;i < size;i++) {
    for (int j =i*i; j <size; j += i) { //ye isliye hai ki uske multiple compositr tick ho jaye 
      sieve[j] = 0; // for composite 
    }
  }
  for (int i = 1; i <size;i++) {
    cout << i << "  " << sieve[i] << endl; 
    if (sieve[i]) {
      c++;
    }
  }
  cout << "Total Prime are -> " << c << endl;
  return 0;
}
