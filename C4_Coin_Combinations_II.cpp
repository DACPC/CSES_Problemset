#import <iostream>
#include <vector>

using namespace std;

int main() {
    const long long MOD = 1e9+7;
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // We will use a dp approach to solve this problem
    // Very similar to last problem
    // DP[i] will be the number of ways to have a sum of i
    // There is 1 way to have $0: no coins
    vector<long long> dp(x + 2, 0);
    dp[0] = 1;

    // Same as last problem, but now we make sure the coins are in order
    for (int coin: coins) {
        for (int i = 0; i < x; i++) {
            dp[min(i + coin, x + 1)] += dp[i];
            dp[min(i + coin, x + 1)] %= MOD;
        }
    }

    cout << dp[x] << endl;

    return 0;
}