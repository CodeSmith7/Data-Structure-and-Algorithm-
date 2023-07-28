#include<iostream>
#include<climits>
using namespace std;
int getMax(int b[],int s)
{ int max  = INT_MIN;
  for (int  i=0;i<s;i++)
   {
    if(max < b[i])
     max=b[i];
   }
   return max;

}
int getMin(int b[], int a)
{
  int min= INT_MAX;
  for (int i=0;i<a;i++)
   {
    if(min > b[i])
     min=b[i];
   }
   return min ;

}

int main()
{  int a[100],size,max,min ;
   cout<<" enter the size of an array";
   cin>>size;
   for(int i=0;i<size;i++)
   cin>>a[i];
   max= getMax(a,size);
   min=getMin(a,size);
   cout<<"maximum element is =  "<<max<<endl;
   cout<<"minimum element is =  "<<min<<endl;
   return 0;
}