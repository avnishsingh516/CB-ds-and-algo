#include <iostream>
using namespace std;

int main() {

    // Allocation
    int b[100] = {0}; //initalise the array with 0
    cout << sizeof(b) << endl;
    cout << b << endl; //symbol table
    // here b cant be overwritten , b is the part of read only memory

    //Dynamic Allocation (on the run time)
    int n;
    cin >> n;
    int *a = new int[n] {0}; //initalise the array with 0
    cout << sizeof(a) << endl;
    cout << a << endl; //variable a that is created inside the static memory can be overwritten
    // like a = new char[30];

    // No Change
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        cout << a[i] << " ";
    }

    // Freeup the Space
    delete [] a;

    return 0;
}
