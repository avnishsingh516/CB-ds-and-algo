#include <iostream>
using namespace std;


int main() {
    int x = 10;
    cout << &x << endl;

    float y = 10.5;
    cout << &y << endl;

    //It doesnt work for character variables
    char ch = 'A';
    //Explicit Typecasing from char* to void*
    //here void* means that we don't known the data type of the variable
    //we need to change it because without it ,it's gives the character stores in ch as output
    cout << "without void* :- " << &ch;
    cout << (void *)&ch << endl;

    return 0;
}
