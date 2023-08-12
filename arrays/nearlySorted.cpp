#include <iostream>
#include<vector>
using namespace std;

int search(vector<int> &a,int t){
  int s = 0;
  int e = a.size() -1;

  while(s <= e){
    int mid = s -(s-e)/2;
    if (a[mid] == t) return mid;
    if (mid+1 < e && a[mid+1] == t) return mid + 1;
    if (mid-1 >= s  && a[mid-1] == t) return mid - 1;

    if (a[mid] > t){
      //left search
      e = mid-2;
    }
    else if(a[mid] < t){
      //right search
      s= mid+2;
    }
  }
  return -1;
}

int main() {
  vector<int> a{10,3,40,20,50,80,70};
  int target = 50;
 cout << "element present at index-> " << search(a,target) << endl;
  return 0;
}