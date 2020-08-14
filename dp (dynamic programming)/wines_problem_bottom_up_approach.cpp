#include<iostream>
using namespace std;

int profitBU(int wines[] , int n ) {

	int dp[1000][1000] = {0};

	//fill the diagnoals first and so on...
	//when we left with 1 wines (i==j) , it means we are currently in last year which is the size of the wines (n)
	for (int i = 0 ; i < n ; i++) {
		dp[i][i] = n * wines[i];
	}

	//l=2 , because we already calculated the profit when the 1 wine is left only
	//so, we have to calculate the profit from when the 2 wines are left
	for (int l = 2 ; l <= n ; l++) {
		for (int s = 0; s <= n - l; s++) {
			int e = s + l - 1;
			int y = n - (e - s);

			if ( (wines[s]*y + dp[s + 1][e]) > (wines[e]*y + dp[s][e - 1]) ) {
				//if we sell the begining wine than the profit is highest
				dp[s][e] = wines[s] * y + dp[s + 1][e];
			}
			else {
				// otherwise, the profit is high if we sell the wine from the end
				dp[s][e] = wines[e] * y + dp[s][e - 1];
			}

		}
	}

	return dp[0][n - 1];

}

int main(int argc, char const *argv[])
{

	int wines[] = {2, 3, 5, 1, 4};
	int n = sizeof(wines) / sizeof(int);
	int y = 1;

	cout << profitBU(wines, n) << endl;

	return 0;
}

/*
For those looking for a bottom up approach , check out the following code by xka ->
https://ide.geeksforgeeks.org/dTif5QO3HS

The idea is quite simple indeed , if you look over the youtube people have only explained the top down approach or they fail to clearly explain the bottom up approach.
So I am giving it a try for future readers

We maintain a dp[i][j] , which tells us the maximum profit we can gain if Total years - i -(Total Years - j) are left or we are at year (i+ Total Years - j -1)
i tells us that i wines from left have been taken into consideration and similarly for j.

What we do is , initialize from i = 0 to i= n , dp[i][i] = n*arr[i]; cause when at i= j, we are at the final year n , and price of that would be n*arr[i].
Meaning when we are left with only one wine to sell at the last stage of our journey.

Now , we start by taking intervals of left wines to sell . For example in the code " l = 2 " states when left with only two wines to sell, and year would be ( total wines sold till now + 1).

Rest of the part is quite intuitive.

dp[i][j] = max(dp[i+1][j] + current_year*arr[i] , dp[i][j-1] + current_year*arr[j] )

Since for L = 2 , when we do dp[i+][j] or dp[i][j-1] , i+1 would be equal to j and j-1 would be equal to i , which part we have already covered by initialization done earlier.

This way we would end up finding dp[0][n-1] which we want as answer , same as in top-down approach.
*/