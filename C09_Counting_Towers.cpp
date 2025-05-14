#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int MOD = (int)(1e9 + 7);

int main() {
  	int t;
    cin >> t;
    // Store the test cases. We will solve dp up to the largest case, and we can answer smalelr cases with cached result
    vector<int> testCases(t);
    for (int i = 0; i < t; i++)
      	cin >> testCases[i];
    int n = *max_element(testCases.begin(), testCases.end());

    // dp[i][0] is the number of ways to construct a tower such that the top row is connected
    // dp[i][1] is the number of ways to construct a tower such that the top row isn't connected
    // for n = 1, we have one of each, a 1x2 and two 1x1's
    // Then to get n = 2, we consideder each case
    // To go from a connected top to a connected top, we can either extend the top or add a new 1x2 (2 ways)
    // To go from an unconnected top to a connected top, we have to add a new 1x2 (1 way)
    // To go from a connected top to an unconnected top, we have to add two 1x1's (1 way)
    // To go from an unconnected top to an unconnected top, we have 4 options:
    // Add two new 1x1's (1 way)
    // Extend one of the 1x1's but not the other (2 ways)
    // Extend both of the 1x1's (1 way)
    // Thus dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1] and dp[i][1] = dp[i - 1][0] + 4 * dp[i - 1][1]
    // for i > 1

    vector<vector<long long>> dp(n + 2, vector<long long>(2, 0));
    // Account for single 2x1 and two 1x1's
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
    	dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
    	dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD;
    }

    // Result will be sum of connected and unconnected tops
    for (int i = 0; i < t; i++)
    	cout << (dp[testCases[i]][0] + dp[testCases[i]][1]) % MOD << endl;

    return 0;
}
