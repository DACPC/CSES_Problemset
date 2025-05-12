#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
    cin >> n;

    // The sum of nums from 1 to n is n * (n + 1) / 2
    // A solution exists if and only if the sum is even
    // Find the smallest set of numbers that adds to half to be in one group, and put everything else in the other

	long long sum = (long long)(n) * (n + 1) / 2;

	if (sum % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}
	else {
		cout << "YES" << endl;
	}

	// Now we care abour half sum
	long long halfSum = sum / 2;

	// If set[i] is the set that the number i will fall in
	vector<short> set(n + 1, 0);
	int setSize = 0;

	// Now we use a sort-of-greedy algorithm to find halfSum
	for (int i = n; i > 0; i--) {
		if (halfSum >= i) {
			set[i] = 1;
			halfSum -= i;
			setSize++;
		}
	}

	// Print first set
	cout << setSize << endl;
	for (int i = 1; i <= n; i++) {
		if (set[i])
			cout << i << " ";
	}
	// Print second set
	cout << endl << n - setSize << endl;
	for (int i = 1; i <= n; i++) {
		if (!set[i])
			cout << i << " ";
	}
	// Remember to flush buffer
	cout << endl;

    return 0;
}