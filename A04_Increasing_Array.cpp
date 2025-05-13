#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
 	int n;
    cin >> n;

	// result is number of increases
    ll result = 0;
	// current minimum number that the next number could be such that the array wouldn't be decreasing
    ll current = 0;

    for (int i = 0; i < n; i++) {
    	// Input the next number
      	ll temp;
        cin >> temp;
		// Calculate the minimum number that this number has to be
		current = max(current, temp);
    	// Update result by operations to get from temp to minimum
    	result += current - temp;
    }

	cout << result;
}
