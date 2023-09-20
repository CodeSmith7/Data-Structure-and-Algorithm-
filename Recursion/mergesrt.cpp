#include <iostream>
#include<stdlib.h>

using namespace std;

void merge(int a[],int s,int mid,int e){
 // int mid = (s+e)/2;
  
  int len1 = mid -s+1;
  int len2 = e-mid;

  // int* left = new int[len1];
  // int* right = new int[len2];

    int* left = (int*)malloc(len1);
    int* right = (int*)malloc(len2);


  //copy value 
  int k =s;
  for(int i=0; i<len1; i++){
  left[i] =a[k];
  k++;
  } 
  k= mid+1;  //important 
  for(int i=0; i<len2; i++){
  right[i] =a[k];
  k++;
  } 

  //merge logic
  int l =0;
  int r= 0;
  int main =s;
  while(l <len1 && r<len2){
    if(left[l]<right[r]){
      a[main++] = left[l++];
    }
    else {
      a[main++] = right[r++];
    }

  }
  //copy remaining left
  while(l<len1){
     a[main++] = left[l++]; 
  } 
  //copy remaining right
  while(r<len2){
     a[main++] = right[r++];
  }

}
void mergeSort(int a[],int s,int e){
  //base case
  //s==e single element
  //s>e invalid  array 
  if(s>=e){
    return;
  }
  int mid = (s+e)/2;
  //left part tsort 
  mergeSort(a,s,mid);
  //right part sort 
  mergeSort(a,mid +1,e);

  //merge 2 sorted array

  merge(a,s,mid,e);
}

int main() {
     int a[]={100,98,87,78,56,34,23,11,8,3,2,1};


     int n = sizeof(a)/sizeof(a[0]);

  
    //    int a[10000];
    // for(int i = 0;i<10000;i++){
    //   a[i] = i;
    // }
    // int n = 10000;
 
 
  int s=0;

  int e =n-1;
  mergeSort(a,s,e);

  for(auto x:a){
    cout<<x<<" ";
  }
  return 0;
}