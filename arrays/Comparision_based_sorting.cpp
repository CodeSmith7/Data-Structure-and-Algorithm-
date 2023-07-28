#include <iostream>
using namespace std;

void bubble_sort(int *a,int n){
  for (int i = 0;i<n-1;i++){
    for(int j = i+1;j<n;j++){
      if(a[i]>a[j]){
        swap(a[i],a[j]);
         }
    }
  }
}
void bubble_sort2(int *a,int n){
  for (int i = 1;i<n;i++){
    for(int j = 0;j<n-i;j++){
      if(a[j]>a[j+1]){
        swap(a[j+1],a[j]);
         }
    }
  }
}

void selection_sort(int *a,int n){
  //isme i ko  n-1 tk chalange kyuni j warna out of bound  nikal jayega

  for (int i = 0;i<n-1;i++ ){
    int min = i ;
    for (int j = i+1;j<n;j++){
      if(a[j]<a[min]){
        min = j ;
      }
    }
    if(i!=min){
      swap(a[i],a[min]);
    }
  }
}

void insertion_sort(int *a,int n){

  for(int i = 1;i<n;i++){
    int  j = i;
     while (j>0 && a[j-1]>a[j]){
       swap(a[j],a[j-1]);
       j--;
     }
 
   }
}



int main() {
  int a[] = {4 ,6,2,1000,269,7,10};
  int n = sizeof(a)/sizeof(a[0]);
  //selection_sort(a,n);
    bubble_sort2(a,n);
  //insertion_sort(a,n);
  for(auto x: a){
    cout << x << " ";
  }
 
  return 0;
}
