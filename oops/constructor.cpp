#include <iostream>
#include<cstring>
using namespace std;

class Car {
private:
    int price;
public:
    int model_no;
    string name;

    //Constructor
    Car() {
        //Override the default Constructor
        cout << "Making a car.." << endl;
    }
    // Constructor with parameters - Parametrised Constructor
    Car(int p, int mn, string n) {
        price = p;
        model_no = mn;
        name = n;

    }
    Car(Car &X) {
        cout << "Making a Copy of Car";
        price = X.price;
        model_no = X.model_no;
        name = X.name;
    }


    void start() {
        cout << "Grrrr...starting the car " << name << endl;
    }
    void setPrice(int p) {
        //setter :- set and update the value of data member
        if (p > 1000) {
            price  = p;
        }
        else {
            price = 1000;
        }
    }
    int getPrice() {
        //getter :- get or give the value of data member
        return price;
    }
    void print() {
        cout << name << endl;
        cout << model_no << endl;
        cout << price << endl;
        cout << endl;
    }

};

int main() {

    Car C;
    //Initialisation
    //C.price =-500;
    C.setPrice(1500);
    C.model_no = 1001;
    C.name = "BMW";
    C.start();

    // cout<<C.price<<endl;
    cout << C.name << endl;
    cout << C.getPrice() << endl;

    Car D;
    D.setPrice(2000);
    cout << D.getPrice() << endl;

    Car E(100, 2001, "Ferrari");
    E.print();

    //Copy Constructor is to create a copy of given object of the same type
    Car F(E); //by default copy constructor or copy constructor
    F.setPrice(2000);
    F.name[0] = 'G'; // only changes the first character
    F.print();
    E.print();

    Car G = F; //it is a different way to call the copy constructor
    G.print();
    F.print();

    return 0;
}

