#include<iostream>
using namespace std;

int partition(int *a, int s, int e) {

    // Inplace (cant take extra array)

    int i = s - 1;  //index of smaller region
    int j = s;      //index of larger region

    int pivot = a[e]; //pivot is always last element

    while (j <= e - 1) {
        if (a[j] <= pivot) {
            //merge in smaller element in the smaller region
            i = i + 1;
            swap(a[i], a[j]);
        }
        //expand the larger region
        j = j + 1;
    }

    //place the pivot element in the correct index
    swap(a[i + 1], a[e]);

    //current index of pivot element
    return i + 1;


}

void quickSort(int a[], int s, int e) {
    //Base case - 1 or 0 elements
    if (s >= e) {
        return;
    }

    //Follow 3 steps
    //1. find the index of pivot element
    int p = partition(a , s , e);


    //Recursively the arrays

    quickSort(a, s, p - 1); //left
    quickSort(a, p + 1, e); //right


}




int main() {

    int a[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;


    return 0;


}