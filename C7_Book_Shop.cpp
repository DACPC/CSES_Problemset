#include <iostream>
#include <vector>
#include <algorithm>

#define iPair pair<int, int>

using namespace std;

int main() {
  	int n, x;
    cin >> n >> x;
    vector<int> cost(n);
    vector<int> pages(n);
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	for (int i = 0; i < n; i++)
		cin >> pages[i];

    // DP[i] is the max number of pages if we spend exactly i money
    // Then, we will consider one book at a time
    vector<int> dp(x + 1, 0);

  	for (int book = 0; book < n; book++) {
    	for (int i = x; i - cost[book] >= 0; i--) {
            dp[i] = max(dp[i], dp[i - cost[book]] + pages[book]);
        }
    }

    // Now find the max amount of pages we can find
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}