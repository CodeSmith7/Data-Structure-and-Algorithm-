#include<iostream>
//#include<bits/stdc++.h>
#include<algorithm>
//#include<utility>
using namespace std;

int main() {
    int a[] = {10,15,5};
    int b[] ={'X','Y','Z'};int,char> pa[3];

    for (int i =0;i<3;i++) {
           pa[i] = {a[i],b[i]};
    }
    sort(pa,pa+3);
    // sorting always happpen according to the first elemn\ent of pair 
    for (int i =0 ;i<3;i++) {
        cout << pa[i].first <<" --> "<<pa[i].second << endl;
    }
} 