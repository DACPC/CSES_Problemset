#include <vector>
#include <iostream>
#include <bitset>
#include <numeric>

using namespace std;

int main() {
  	int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
      	cin >> coins[i];
    }

    // Use bitset to mark reachable values
	bitset<100001> reachable;
	reachable |= 1;

	for (int coin: coins) {
		reachable |= reachable << coin;
	}

	// Make sure not to count 0
	reachable >>= 1;

	// Count set bits
	int count = 0;
	bitset<100001> temp = reachable;
	while (temp != 0) {
		if (temp[0])
			count++;
		temp >>= 1;
	}
	cout << count << endl;

	// Output the position of set bits
	int i = 1;
	while (reachable != 0) {
		if (reachable[0])
			cout << i << " ";
		reachable >>= 1;
		i++;
	}

	cout << endl;

	return 0;
}