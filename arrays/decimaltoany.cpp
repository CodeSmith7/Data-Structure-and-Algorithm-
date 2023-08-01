#include<iostream>
using namespace::std;
int decimaltoany(int n,int b)
{
    int p=1,ans=0;
	while(n>0)
	{
	    int digit= n%b;
	    n =  n/b;
	    ans += digit*p; //agr same rakhna hai to digit main multiply 10 karte hain 
	    p = p*10;       //123 -> 321  --> ans = ans *10 + digit 
	}
	
	return ans;
}

int main()
{    int base,decimal;

    cout<<"Enter the value of decimal number that you want to convert"<<endl;
    cin>>decimal;
    cout<<"Enter the base you want to convert"<<endl;
    cin>>base;
    cout<<decimal<<" to base "<<base<<"  is :  " <<decimaltoany(decimal,base);
    return 0;
}