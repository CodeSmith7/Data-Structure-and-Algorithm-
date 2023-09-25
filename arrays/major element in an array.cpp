#include <vector>
#include <iostream>
#include<unordered_map>
using namespace std;

int majorityEleHashMap(vector<int> &nums) {
  unordered_map<int,int> mp;
  int maxi = -1;
  int ans = -1;
  for (auto x : nums) {
      mp[x]++;
   }
  for (auto it : mp) {
    if (it.second > maxi) {
      maxi = it.second;
      ans = it.first;
    }
  }
   for (auto it : mp){
    cout << it.first << "  " << it.second << endl;
   }
   cout << "maxi is : -> " << maxi << endl;
   cout << "ans is : -> " << ans << endl;


}


//ye acha hai 
int majorityElementMoore(vector<int> &a) {
      int size = a.size();
       int fcount=0;
        int ansIndex=0;
        int count=1;
        for(int i=1;i<size;i++)
        {
            if(a[i]==a[ansIndex])
                count++;
            else
                count--;
            if(count<0)
            {
                count=1;
                ansIndex=i;
            }
        }
//after iteration of above loop we have index of major element in an array 

        //for checking it really is an majority element 
        for(int i=0;i<size;i++) {
            if(a[i]==a[ansIndex])
                fcount++;
        }
            if(fcount>size/2)
              return a[ansIndex];
            
        return -1;
}



//ye booish hain 
int majorityElement(std::vector<int>& nums) {
    //Boyer Moore Voting algorithm 

    int count = 0;
    int candidate = -1;


    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}



int main() {
    std::vector<int> nums = {3,4,5,3,4,5,6,2,3,6,3,3,3,3,6,10,6,6,6,3,3,33,3,3,3,3,3,3,3};
    std::cout << "Majority Element is: " << majorityElement(nums) << std::endl;
    majorityEleHashMap(nums);
    cout << "majority element by moore algom is : -> " << majorityElementMoore(nums) << endl;
    return 0;
}
