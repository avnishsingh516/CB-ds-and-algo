#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll coins[40];

ll optimalGame(ll i, ll j) {
    if (i > j) {
        return 0;
    }

    // Consider both the possibilities. You can pick either the first or the last coin.
    // Since the opponent plays optimally , we would get the minimum of the remaining coins for each choice.
    ll pickFirst = coins[i] + min( optimalGame(i + 2, j) , optimalGame(i + 1, j - 1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i, j - 2) , optimalGame(i + 1, j - 1) ) ;

    // Pick the max of two as your final result
    ll ans = max(pickFirst, pickLast);

    return ans;
}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << optimalGame(0, n - 1);

    return 0;
}

/*
for efficient way :- https://www.geeksforgeeks.org/optimal-strategy-for-a-game-set-2/


int oSRec(int arr[], int i, int j, int sum)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);

    // For both of your choices, the opponent
    // gives you total sum minus maximum of
    // his value
    return max((sum - oSRec(arr, i + 1, j, sum - arr[i])),
            (sum - oSRec(arr, i, j - 1, sum - arr[j])));
}

// Returns optimal value possible that a player can
// collect from an array of coins of size n. Note
// than n must be even
int optimalStrategyOfGame(int* arr, int n)
{
    int sum = 0;
    sum = accumulate(arr, arr + n, sum);
    return oSRec(arr, 0, n - 1, sum);
}

// Driver program to test above function
int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0 ; i<n ;i++)
        cin>>a[i];

    cout<<optimalStrategyOfGame(a,n);

    return 0;
}
*/