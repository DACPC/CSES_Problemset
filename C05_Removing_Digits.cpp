#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Use a greedy algorithm, and always subtract the largest digit
    int result = 0;
    while (n > 0) {
        // Find the largest digit
        int temp = n;
        int maxDigit = 0;
        while (temp > 0) {
            maxDigit = max(maxDigit, temp % 10);
            temp /= 10;
        }
        // Subtract the largest digit
        n -= maxDigit;
        result++;
    }

    cout << result << endl;

    return 0;
}
