#include<iostream>
using namespace std;
//brute force approach 
// time complecity -> O(n^3) and sc O(1)
int trap1(int *a,int n) {
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, a[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, a[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - a[i];
  }
  return waterTrapped;
}
//better solution 
// time  complexity -> O(n^2) Space Complexity: O(N)+O(N) for prefix and suffix arrays.
int trap2(int *a,int n) {
  int prefix[n], suffix[n];
  //computing prefix array
  prefix[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], a[i]);
  }
  //computing suffix array
  suffix[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], a[i]);
  }
  
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - a[i];
  }
  return waterTrapped;

}
//optimal solution using two pointer approach 
// space complexity -> O(1) and time copmplexity -> O(n)
int trap3(int *a ,int n) {
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  
  while (left <= right) {
  
    if (a[left] <= a[right]) {
      
      if (a[left] >= maxLeft) {
        maxLeft = a[left];
      } else {
        res += maxLeft - a[left];
      }
      
      left++;
    
    } else {
     
      if (a[right] >= maxRight) {
        maxRight = a[right];
      } else {
        res += maxRight - a[right];
      }
      
      right--;
    }
  }
  return res;
}
int main() {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "maximum trapped water is -> " << trap1(a,n) << endl;
    cout << "maximum trapped water is -> " << trap2(a,n) << endl;
    cout << "maximum trapped water is -> " << trap3(a,n) << endl;
    return 1;
}