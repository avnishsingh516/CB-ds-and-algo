// Optimised Bitset Code to count all configurations

#include<iostream>
#include<bitset>
using namespace std;

// it counts the no of ans
//d1 - left diagonal
//d2 - right diagonal
bitset<30> col, d1, d2;

void solve(int r, int n, int &ans) {
    if (r == n) { ans++; return;}

    for (int c = 0; c < n; c++) {
        if ( !col[c] && !d1[r - c + n - 1] && !d2[r + c]) {
            col[c] = d1[r - c + n - 1] = d2[r + c] = 1;
            solve(r + 1, n, ans);
            col[c] = d1[r - c + n - 1] = d2[r + c] = 0;
        }
    }
}

int main() {
    int n = 4;
    // cin >> n;
    int ans = 0;
    solve(0, n, ans);
    cout << ans << endl;

    return 0;
}