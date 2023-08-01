#include <bits/stdc++.h>
using namespace std;

// Function to find the next permutation
void nextPermutation(vector<int>& arr)
{
	//next_permutation(arr.begin(),arr.end());
  int index = -1;
  int n = arr.size();
  //just fiinding the break point 
  for (int i =n-2;i>=0;i--){
       if(arr[i+1]>arr[i]){
         index = i;
         break;
       }
  }
  if (index == -1){
    reverse(arr.begin(),arr.end());
    return;
  }
  for (int i =n-1;i>index;i--){
    if (arr[i]>arr[index]){
      swap(arr[i],arr[index]);
      break;
    }
  }
  //reverse from the place you find break point 
  reverse(arr.begin()+index+1,arr.end());

  
}

// Driver code
int main()
{
                    
	// Given input array
	vector<int> arr = {2,1,5,4,3,0,0 };

	// Function call
	//nextPermutation(arr);
  next_permutation(arr.begin(),arr.end());
  
	// Printing the answer
	for (auto i : arr) {
		cout << i << " ";
	}

	return 0;
}
