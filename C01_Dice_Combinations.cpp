#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // When approaching a DP problem, think of the general case
    // What are the ways to roll n?
    // Roll a combination that sums to n-6 then roll 6
    // Roll a combination that sums to n-5 then roll 5
    // Roll a combination that sums to n-4 then roll 4
    // Roll a combination that sums to n-3 then roll 3
    // Roll a combination that sums to n-2 then roll 2
    // Roll a combination that sums to n-1 then roll 1
    // Thus dp[n] = dp[n-6] + dp[n-5] + dp[n-4] + dp[n-3] + dp[n-2] + dp[n-1]
    // Our basic cases will be the following:
    // dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4, dp[4] = 8, dp[5] = 16
    // If we add everything in dp up till i-1, it will equal dp[i-1] * 2
    // Thus we can simplify our previous dp equation to the following:
    // dp[n] = 2 * dp[n-1] - dp[n-7];

    vector<long long> dp(max(7, n + 1));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    for (int i = 7; i <= n; i++) {
        dp[i] = (dp[i - 1] * 2 - dp[i - 7] + 1000000007) % 1000000007;
    }

    cout << dp[n];

    return 0;
}
