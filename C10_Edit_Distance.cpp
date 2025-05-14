#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int main() {
  	string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    // 2D dp approach, where dp[i][j] is the number of transformations to get from s1.substr(0,i) to s2.substr(0,j)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    // It doesn't take any transformations to get from empty string to empty string
    dp[0][0] = 0;
    // It takes i transformations to go from a string of length i to an empty string
    for (int i = 1; i <= n; i++)
      	dp[i][0] = i;
    for (int j = 1; j <= m; j++)
      	dp[0][j] = j;
    // Now, we will iterate through the 2d dp array in row-major order
    // To get to dp[i][j], we could've:
    // Had a shared letter at s1[i] and s2[j], thus dp[i][j] = dp[i-1][j-1]
    // Added a letter to s1 or s2, thus dp[i][j] = dp[i-1][j] + 1 or dp[i][j-1] + 1 respectively
    // Adding a letter to s1 is the same a removing a letter at s2, and visa versa
    for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= m; j++) {
	    	if (s1[i - 1] == s2[j - 1]) {
	    		dp[i][j] = dp[i - 1][j - 1];
	    	}
	    	dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), min(dp[i][j] - 1, dp[i - 1][j - 1])) + 1;
	    }
    }


    cout << dp[n][m] << endl;

    return 0;
}