#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#define ll long long
using namespace std;

int main() {
  	int n;
    cin >> n;
    vector<int> apples(n);
	ll sum = 0;
    for (int i = 0; i < n; i++) {
      	cin >> apples[i];
        sum += apples[i];
    }

    // Brute-force the solutions
    // We will use a bitmask to represent which apples to have in each group
	// By incrementing the bitmask from 0 to 2^n - 1, we get every combination of 1's and 0's with n bits
    int mask = 0;
    ll result = LONG_LONG_MAX;
    while (mask < (1 << n)) {
      	ll curWeight = 0;
      	// Find the sum of weights from current mask
        for (int i = 0; i < n; i++) {
	        if (mask & (1 << i))
	        	curWeight += apples[i];
        }
    	result = min(result, abs(sum - 2 * curWeight));
    	mask++;
    }

    cout << result << endl;

    return 0;
}