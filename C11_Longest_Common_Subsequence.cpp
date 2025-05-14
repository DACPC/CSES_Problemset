#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  	int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    for (int i = 0; i < n; i++)
      	cin >> v1[i];
    for (int i = 0; i < m; i++)
      	cin >> v2[i];

	// 2D dp approach, where dp[i][j] is the length of the longest subsequence until i and j of array 1 and 2
    // i.e. longest subseq. of subarrays until i and j non-inclusive
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++) {
      	for (int j = 0; j < m; j++) {
          	if (v1[i] == v2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            dp[i + 1][j + 1] = max(max(dp[i][j], dp[i + 1][j + 1]), max(dp[i + 1][j], dp[i][j + 1]));
        }
    }

	cout << dp[n][m] << endl;
	// Now print the matches
	// We will work backwards, constructing the subsequence in reverse, then print it reversed again
	// We will only move up, left or diagonally trying to maximize dp[i][j] at every step
	// Once dp[i][j] has no choice but to decrease, we move diagonally, and include that number
	vector<int> result;
	result.reserve(dp[n][m]);

	int i = n, j = m;
	// End once either reaches 0, as there is no number to be common
	while (i > 0 && j > 0) {
		// Find biggest neighbor
		int biggestNeighbor = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]);
		// If biggest is not same as dp[i][j], we move diagonally, and append to result
		if (dp[i][j] != biggestNeighbor) {
			i--;
			j--;
			result.push_back(v1[i]);
			continue;
		}
		if (dp[i - 1][j - 1] == biggestNeighbor) {
			i--;
			j--;
		}
		else if (dp[i][j - 1] == biggestNeighbor) {
			j--;
		}
		else if (dp[i - 1][j] == biggestNeighbor) {
			i--;
		}
	}

	// Result is in reverse right now, print it backwards
	for (int k = dp[n][m] - 1; k >= 0; k--)
		cout << result[k] << " ";
	cout << endl;

    return 0;
}