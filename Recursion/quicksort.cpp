#include <iostream>
using namespace std;

int partition(int a[],int s,int e){

  //step 1: choose pivot element
  int pivotIndex =s;
  int pivotElement =a[s];

  //step 2: how amny elements lesser than pivot element 
  int count =0;
  for(int i=s+1;i<=e;i++){
     if(a[i]<=pivotElement){
      count++;
    }
  }
  //
  int rigthIndex = s + count;
  swap(a[pivotIndex],a[rigthIndex]);
  pivotIndex = rigthIndex;

  //step3: left main chote right main bde 
  int i=s;
  int j=e;
  while(i<pivotIndex && j> pivotIndex){
       while(a[i]<=pivotElement){
         i++;
       }
       while(a[j]>pivotElement){
         j--;
       }
       //2 case
       //A-> you the elements to swap 
       //B-> no need to swap 

       if(i<pivotIndex && j> pivotIndex){
         swap(a[i],a[j]);
       }

  }
  return pivotIndex;
}

void quicksort(int a[],int s, int e){
  //base case
  if(s>=e){
    return;
  }

  //partition logic,return pivot index 
  int p = partition(a,s,e);

  //recursive cALLS
  //pivot element -> left 
  quicksort(a,s,p-1);
  //pivot element _> right 
   quicksort(a,p+1,e);
}



int main() {
   // int a[]={100,98,87,78,56,34,23,11,8,3,2,1};
      int a[] = {4 ,6,2,1,9,269,7,10};

    int n = sizeof(a)/sizeof(a[0]);

    // int a[10000];
    // for(int i = 0;i<10000;i++){
    //   a[i] = i;
    // }
    // int n = 10000;
    int s=0;
    int e =n-1;
    quicksort(a,s,e);
    for (auto x: a){
      cout<<x<<" ";
    }
  return 0;
}