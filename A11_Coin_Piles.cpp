#include <iostream>

using namespace std;

void solve() {
	long a, b;
    cin >> a >> b;

    // Each move removes 3 coins, thus the total number of coins needs to be divisible by 3
    // Then, the size of one pile cant be more than double of the other, otherwise, it can't get emptied

    if ((a + b) % 3 != 0) {
      	cout << "NO" << endl;
        return;
    }

    if (a * 2 < b || b * 2 < a) {
    	cout << "NO" << endl;
		return;
    }

    cout << "YES" << endl;
}

int main() {
  	int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
      	solve();
    }
}