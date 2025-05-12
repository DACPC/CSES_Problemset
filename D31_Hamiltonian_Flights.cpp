// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<int> emptyVec;
    emptyVec.reserve(21);

    vector<vector<int>> graph(n + 1, emptyVec);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        graph[a].push_back(b);
    }

    // cout << "Got inputs" << endl;

    vector<vector<int>> dp((1 << n), vector<int>(n + 1, 0));
    dp[1][1] = 1;

    for (int i = 1; i <= (1 << n); i += 2) {
        // cout << "Checking possibility: " << i << endl;
        //  From here, check which possibilities of starting points I can be at
        for (int j = 1; j < n; j++) {
            // cout << "Am I at " << j << endl;
            //  If this city is visited, it could be the current
            if ((((1 << (j - 1)) & i) > 0) && dp[i][j] > 0) {
                // cout << "I am at " << j << endl;
                for (const auto& edge: graph[j]) {
                    // cout << "Potential edge to " << edge << endl;
                    int nextCity = 1 << (edge - 1);
                    if (!((i & nextCity) > 0)) {
                        // cout << "Adding possibility at " << (i | nextCity) << endl;
                        dp[i | nextCity][edge] = (dp[i | nextCity][edge] + dp[i][j]) % 1000000007;
                    }
                }
            }
        }
    }

    // for (const auto& r: dp) {
    //     for (const auto& c: r) {
    //         cout << c << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[(1 << n) - 1][n] << endl;

    return 0;
}