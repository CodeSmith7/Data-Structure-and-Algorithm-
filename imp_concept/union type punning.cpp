#include <iostream>

using namespace std;


union s {
    int x;
    float y;
};

int main()
{    s ob;
    cout<<sizeof(s) << endl;
    ob.y= 3.6;
    cout << ob.x;
    
//by using type puning we get to know how decmal or other type of variable are represented 
    return 0;
}
