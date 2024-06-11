#include<iostream>
using namespace std;


class Rectangle{

  int Length, Breadth;
  public:

  Rectangle() {
     Length = 0;
     Breadth = 0;
  }
   
  
  void operator ++() {
      Length+=2;
     Breadth+=2;
  }


  void Display() {
    cout  << "Length = " << Length <<"  Breadth =  " << Breadth << endl;
  }
};

int main() {
  Rectangle R;
  R.Display();
  ++R;
  //R++;  //This statement gives error   void operator ++(int) {
  R.Display();
  return 0;
}
