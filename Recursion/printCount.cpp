#include<iostream>
using namespace std;

void printF(int n) {
    if (n <= 0) {
        return;
    }
    printF(n-1);
    cout << n << " ";

}
void printB(int n) {
    if (n <= 0) {
        return;
    }
    cout << n << " ";
    printB(n-1);
}
int main() {
    int n;
    cout << "Enter number to print counting " << endl;
    cin >> n;
    cout << "In forward direction " << endl;
    printF(n);
    cout << "fromn to zero " << endl; 
    printB(n);
    return 0;

}
