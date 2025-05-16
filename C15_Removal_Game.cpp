#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int main() {
  	int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
      	cin >> nums[i];

    // Store prefix sums to have O(1) lookup for subarray sums
    vector<ll> pref(n + 2);
    pref[0] = 0;
    for (int i = 0; i < n; i++)
      	pref[i + 1] = pref[i] + nums[i];

    // 2D dp approach, n x n x 2
    // dp[i][j] represents the max scores if we played the game with only the numbers from index i to j inclusive
    // ignore indices where j < i
    // In the general case, we could either take the left or the right
    // If we take from the left, our max score is the max score if we play as second player without the left number
    // If we take from the right, our max score is the max score if we play as second player without the right number
    // The max score if we play as the second player is the total sum - the max score as the first player
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    // If we play the game with one singular number, the max score is that one number
    // It doesn't matter what side we take from, we get the same score
    for (int i = 0; i < n; i++)
      	dp[i][i] = nums[i];

    // Right now, our dp only has the top-left to bottom-right diagonal filled
    // We will fill in the array towards the top-right corner
    // Ignore the bottom-left half
    for (int i = n - 1; i >= 0; i--) {
      	for (int j = i + 1; j < n; j++) {
          	// See the result if we take the first from left
            // Traverse to i, j from i + 1, j
            // Score as second player + score if we take this one
            dp[i][j] = pref[j + 1] - pref[i + 1] - dp[i + 1][j] + nums[i];
      		// See the result if we take the first from right
      		// Traverse to i, j from i, j - 1
      		// Score as second player + score if we take this one
      		dp[i][j] = max(dp[i][j], pref[j] - pref[i] - dp[i][j - 1] + nums[j]);
        }
    }

    // for (const auto& row: dp) {
    //   	for (const auto& col: row)
    //       	cout << col[0] << "," << col[1] << " / ";
    //     cout << endl;
    // }

	cout << dp[0][n - 1] << endl;

    return 0;
}