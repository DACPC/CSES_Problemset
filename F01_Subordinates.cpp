#include <iostream>
#include <vector>

using namespace std;

void findSubordinates(vector<vector<int>>& graph, vector<int>& numSubs, int employee) {
	// Avoid repeats
  	if (numSubs[employee] != -1)
        return;
    numSubs[employee] = 0;

    // Traverse to all children
  	for (int sub: graph[employee]) {
        findSubordinates(graph, numSubs, sub);
        numSubs[employee] += numSubs[sub] + 1;
    }
}

int main() {
  	int n;
    cin >> n;

    // Treat the problem as a graph, so rather than take the input as an array, we will construct the graph
    // Each employee is a node, and they share an edge if one employee is the other's direct boss
    // For convenience, the graph will be directed, from higher ranking to lower ranking
    vector<vector<int>> graph(n);
    int temp;
    for (int i = 1; i < n; i++) {
      	cin >> temp;
        graph[temp - 1].push_back(i);
    }

    // Do a DFS traversal to get the counts
    // For each employee, their number of subordinates is the number of edges + their suboordinates
    vector<int> numSubordinates(n, -1);
    findSubordinates(graph, numSubordinates, 0);

    for (int numSubs: numSubordinates)
      	cout << numSubs << " ";
    cout << endl;

    return 0;
}
