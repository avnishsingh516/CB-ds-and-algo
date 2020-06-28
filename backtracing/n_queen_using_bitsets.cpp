// Bitset Code to Print all configurations
#include<iostream>
#include<bitset>
using namespace std;


// Here we don’t need to write is Safe Positon Function which works in linear time instead we use bitsets which work in O(1) time.

//bool array take 1 byte and bitset take 1 bit
//bit set reduced the space complexity
// it reduced the time complexity to O(1) , where isSafe works in O(n) time
bitset<30> col, d1, d2;
//d1 - left diagonal
//d2 - right diagonal
int board[15][15] = {0};


void printboard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void solve(int r, int n, int &ans) {
    if (r == n) {
        ans++;
        printboard(n);
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !d1[r - c + n - 1] && !d2[r + c]) {

            col[c] = d1[r - c + n - 1] = d2[r + c] = board[r][c] = 1;
            solve(r + 1, n, ans);
            col[c] = d1[r - c + n - 1] = d2[r + c] = board[r][c] = 0;
        }
    }
}

int main() {
    int n = 4;
    // cin>>n;
    int ans = 0;
    solve(0, n, ans);
    cout << ans << endl;

}