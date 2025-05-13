#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // This vector will represent whether each index has appeared
    // i.e. arr[i] = true iff i has appeared
    vector<bool> arr(n + 1, false);

    // Set all the input numbers to true
    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;

        arr[temp] = true;
    }

    // Find the number that hasn't been included in input, i.e. arr[i] = false
    for (int i = 1; i <= n; i++) {
        if (!arr[i]) {
            cout << i << endl;
        }
    }
}
