#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // We will use a dp array of combinations we can add up to
    // dp[i] = minimum coins to get to a sum of i, INT_MAX if we can't reach
    vector<int> dp(x + 2, INT_MAX);
    dp[0] = 0;
    // We can make a sum of 0 with no coins
    // We will ignore all values > x and treat it as x + 1

    // Now we will add coins in one by one
    for (int coin: coins) {
        // Now we check which values we can add up to
        for (int i = 0; i < x; i++) {
            if (dp[i] != INT_MAX) {
                dp[min(x + 1, i + coin)] = min(dp[min(x + 1, i + coin)], dp[i] + 1);
            }
        }
    }

    // If the solution for x is still INT_MAX, we havent found a combination to get there
    if (dp[x] == INT_MAX) {
        cout << -1;
    }
    else {
        cout << dp[x];
    }

    return 0;
}