class Solution {
public:
    
    vector<int> getRow(int rowIndex) {
       int r = rowIndex+1;
       long long ans = 1;
       vector<int>  row;
       row.push_back(1);
       //calculating rest of element 
       for (int c = 1;c<r;c++) {
           ans = ans * (r-c);
           ans = ans / c;
           row.push_back(ans);
       }    
       return row;    
    }
};
