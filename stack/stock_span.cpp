#include <iostream>
#include <stack>
using namespace std;

void printSpan(int arr[], int n) {
    stack<int> s;
    int ans[100] = {};
    for (int day = 0; day < n; ++day) {
        int curPrice = arr[day];
        while (s.empty() == false && arr[s.top()] < curPrice) {
            s.pop();
        }


        if (s.empty()) {
            //now either my stack will be empty or there is no element greater than this currday
            s.push(day);
            ans[day] = 0;
        }
        else {
            //there is a better value than my current element a[i]
            int span = day - s.top();
            ans[day] = span;
            s.push(day);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}

int main() {
    int n = 8;
    int arr[100] = {100, 80, 60, 70, 60, 75, 85 , 111};

    printSpan(arr, n);

    return 0;
}