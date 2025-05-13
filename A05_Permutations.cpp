#include <iostream>

using namespace std;

int main() {
	int n;
    cin >> n;

	// Edge cases for no solution, or solutions that might not work with our solution
    if (n == 1) {
      	cout << "1" << endl;
    	return 0;
    }
	if (n == 4) {
		cout << "2 4 1 3" << endl;
		return 0;
	}
    if (n < 5) {
    	cout << "NO SOLUTION" << endl;
        return 0;
    }

    // First, print odds, then evens, this guarantees that they are separate
    for (int i = 1; i <= n; i += 2) {
      	cout << i << " ";
    }
    for (int j = 2; j <= n; j += 2) {
      	cout << j << " ";
    }

	cout << endl;

    return 0;
}
