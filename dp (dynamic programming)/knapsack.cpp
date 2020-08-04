// after 3 hr :- https://youtu.be/X7SrnbgqHHs
//it can only pick a item once
#include<iostream>
using namespace std;

int knapsack(int wts[], int prices[], int N, int W) {
    ///Base Case
    if (N == 0 || W == 0) {
        return 0;
    }

    ///Rec Case
    int inc = 0, exc = 0;
    if (wts[N - 1] <= W) {
        inc = prices[N - 1] + knapsack(wts, prices, N - 1, W - wts[N - 1]);
    }

    exc = knapsack(wts, prices, N - 1, W);

    return max(inc, exc);
}

int knapsackDP(int wt[], int price[], int N, int W) {
    int dp[100][100] = {0};


    for (int n = 0; n <= N; n++) {
        for (int w = 0; w <= W; w++) {

            if (n == 0 || w == 0) {
                dp[n][w] = 0;
            }
            else {
                int inc = 0, exc = 0;
                if (wt[n - 1] <= w) {

                    inc = price[n - 1] + dp[n - 1][w - wt[n - 1]];
                }
                exc = dp[n - 1][w];

                dp[n][w] = max(inc, exc);

            }

        }
    }
    return dp[N][W];
}





int main() {

    int wts[] = {2, 7, 3, 4};
    int prices[ ] = {5, 20, 20, 10};

    int N = 4;
    int W = 11;
    cout << knapsack(wts, prices, N, W) << endl;;

    cout << knapsackDP(wts, prices, N, W) << endl;

    return 0;
}
