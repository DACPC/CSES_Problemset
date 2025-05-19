#include <iostream>
#include <vector>

using namespace std;

// Returns {edges from this node to furthest node, furthest edge}
pair<int, int> DFS(vector<vector<int>>& graph, int cur, int parent) {
  	// If no more connections, furthest node is itself
  	pair<int, int> result = {0, cur};

    for (int edge: graph[cur]) {
      	if (edge == parent)
          	continue;

      	pair<int, int> child = DFS(graph, edge, cur);
        // Add one more distance to child
        child.first++;

        // Then check if going this way will reach further
        if (child.first > result.first)
          	result = child;
    }

    return result;
}

int main() {
	int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; i++) {
      	int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // We can assume that the furthest nodes will both only be connected to 1 node due to the tree structure
    // Choose any node that is only connected to one other node
    // From there, use DFS to find the furthest node from here
    // From that node, find the furthest node. That will distance will be the diameter

    int start = -1;
    for (int i = 1; i <= n; i++)
      	if (graph[i].size() == 1) {
          	start = i;
            break;
        }

    // Now we have the first node, dfs until we find the furthest node from here
    int d1 = DFS(graph, start, -1).second;

    // Then print the longest path from there
    cout << DFS(graph, d1, -1).first;

  	return 0;
}