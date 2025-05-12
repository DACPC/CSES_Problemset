#include <iostream>
using namespace std;

int main() {
    // n needs to be long long to prevent overflow
    long long n;
    cin >> n;
    // Keep repeating until n becomes 1
    while (n != 1) {
        // Print the current number
        cout << n << " ";

        // If even, half it, if odd, triple it and add 1
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = n * 3 + 1;
        }
    }
    // Last number is 1
    cout << 1 << endl;
}