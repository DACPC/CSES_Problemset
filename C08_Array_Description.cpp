#include <iostream>
#include <vector>

using namespace std;

static const int MOD = (int)(1e9 + 7);

int main() {
  	int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    	cin >> nums[i];

    // Use a 2d DP array where dp[i][j] is the number of ways for the ith digit to be j
   	// First pass: mark unreachables with -1
    // Second pass: calculate DP when nums[i] == 0
    // Keep an upper and lower buffer on dp that is just -1
    vector<vector<long>> dp(n, vector<long>(m + 2, 0));

    // First pass going forwards
    int upperBound = m;
    int lowerBound = 1;

	for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
			upperBound = nums[i];
			lowerBound = nums[i];
        }
        for (int j = 0; j < lowerBound; j++)
            dp[i][j] = -1;
        for (int j = upperBound + 1; j <= m + 1; j++)
          	dp[i][j] = -1;

		upperBound = min(m, upperBound + 1);
		lowerBound = max(1, lowerBound - 1);
    }
    // First pass going backwards
    upperBound = m;
    lowerBound = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (nums[i] != 0) {
			upperBound = nums[i];
			lowerBound = nums[i];
		}
		for (int j = 0; j < lowerBound; j++)
			dp[i][j] = -1;
		for (int j = upperBound + 1; j <= m; j++)
			dp[i][j] = -1;

		upperBound = min(m, upperBound + 1);
		lowerBound = max(1, lowerBound - 1);
	}

    // Second pass
    // First set initial values
    if (nums[0] == 0)
      	for (int j = 1; j <= m; j++)
          	dp[0][j] = 1;
    else
      	dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++) {
      	// We can get to dp[i][j] from dp[i-1][j] or dp[i-1][j-1] or dp[i-1][j+1] if they are reachable
        for (int j = 1; j <= m; j++) {
          	if (dp[i][j] == -1)
                continue;
            if (dp[i - 1][j - 1] != -1) {
              	dp[i][j] += dp[i - 1][j - 1];
            	dp[i][j] %= MOD;
            }
            if (dp[i - 1][j] != -1) {
              	dp[i][j] += dp[i - 1][j];
            	dp[i][j] %= MOD;
            }
            if (dp[i - 1][j + 1] != -1) {
              	dp[i][j] += dp[i - 1][j + 1];
            	dp[i][j] %= MOD;
            }
        }
    }

    int result = 0;
    for (int j = 1; j <= m; j++) {
      	if (dp[n - 1][j] != -1) {
          	result += dp[n - 1][j];
      		result %= MOD;
        }
    }

    cout << result << endl;

    return 0;
}
