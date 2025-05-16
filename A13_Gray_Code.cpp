#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  	int n;
    cin >> n;

    // Use a recursive/dp-like solution:
    // Base case: 0, 1
    // Then we will add zeroes in front of it, and then add ones in front of it but backwards
    // Thus guarantees that everything has a hamming distance of 1
    // 00, 01, 11, 10
    // Then we do the same thing agin
    // 000, 001, 011, 010, 110, 111, 101, 100

    vector<vector<string>> dp(n);
    dp[0] = {"0", "1"};

    for (int i = 1; i < n; i++) {
      	for (string s: dp[i - 1])
          	dp[i].push_back("0" + s);
        for (int j = dp[i - 1].size() - 1; j >= 0; j--)
          	dp[i].push_back("1" + dp[i - 1][j]);
    }

    for (string s: dp[n - 1])
      	cout << s << endl;

    return 0;
}