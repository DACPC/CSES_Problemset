#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

void DFS(vector<vector<int>>& graph, vector<vector<int>>& dp, int cur, int parent) {
	// First, we assume number of pairs is 0 other than this one
	dp[cur][0] = 0;
	dp[cur][1] = 1;

	// Then we want to be greedy in including more children
	int mostConnectedChild = 0;

	// Now we search all children
	for (const auto& edge: graph[cur]) {
		// Ignore the parent
		if (edge == parent)
			continue;
		// Otherwise DFS the child node
		DFS(graph, dp, edge, cur);

		// The most edges including this one is 1 + the most edges not including its children
		dp[cur][1] += dp[edge][0];
		// The most edges not including this one is the most edges not including its children
		// It can contain only 1 edge with children
		dp[cur][0] += dp[edge][0];

		// If we don't include the edge into cur, we can only include one edge out, so choose the best one
		if (dp[edge][1] - dp[edge][0] > dp[mostConnectedChild][1] - dp[mostConnectedChild][0])
			mostConnectedChild = edge;
	}

	dp[cur][0] -= dp[mostConnectedChild][0];
	dp[cur][0] += dp[mostConnectedChild][1];
}

int main() {
  	int n;
    cin >> n;
    vector<vector<int>> graph(n + 2);
    for (int i = 1; i < n; i++) {
      	int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Take a dp approach
	// DP[i][0] will be max pairs if we don't include edge into node i
	// DP[i][1] will be max pairs if we do include edge into node i
	// We will arbitrarily treat node 1 as the root
	// DFS recursively
	vector<vector<int>> dp(n + 1, {0, 0});

	DFS(graph, dp, 1, -1);

	// No edge into node 1
	dp[1][1]--;

	cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}
