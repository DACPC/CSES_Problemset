#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MOD = 1000000007;
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // If we top left is a mine, we can't go anywhere
    if (grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }

    // Use a 2D dp array
    // dp[i][j] = number of ways to get to (i, j)
    vector<vector<long>> dp(n, vector<long>(n, 0));
    // We start at 0,0
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // We can move to (i,j) from i-1 or j-1 if it isn't a *
            // Ignore * tiles
            if (grid[i][j] == '*') {
                continue;
            }

            // Otherwise, check up and left
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }

            dp[i][j] %= MOD;
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}