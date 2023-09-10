#include <iostream>
#include <string.h>
using namespace std;

// from left to right 
void lastOcur(string &s,char x,int i,int &ans) {
    // base case 
    if (i >= s.size()) {
        return;
    }

    if (s[i] == x) {
        ans = i;
    }
    lastOcur(s,x,i+1,ans);
}
// last occurence right to left (first encounter is last character )
void lastOcurRL(string &s,char x,int i,int &ans) {
    // base case 
    if (i < 0) {
        return;
    }

    if (s[i] == x) {
        ans = i;
        return;
    }
    lastOcurRL(s,x,i-1,ans);
}
int main (){

    string s ="abddeedhj";
    char a[]= "abddeedhj";
    char x = 'd';
    int ans;
    lastOcurRL(s,x, s.size() - 1 ,ans);
   // cout << "last ocuurence of charcter is -> " <<  ans  << endl;

    // last character using STL strrchar()
    // syntax :  char *strrchr(const char *str, int c)
    //"Last occurrence of %c in %s is at index %d",   chr, str, ptr - str);

    cout  << "last occurence is at -> " << strrchr(a,x) - a << endl;

 
    return 0;

}