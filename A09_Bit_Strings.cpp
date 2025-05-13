#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n;
	cin >> n;

    // Mode constant
    const long long MOD = 1e9+7;

    // There are 2^n possible bit strings as each bit of the n bits can be on or off (2 states)
    // We will a modular exponentiation kind of approach (MODULAR EXPONENTIATION IS A MUST-KNOW!!)
    // long longs are used to prevent overflow

    // Find the leftmost bit
    int leftMost = 0;
    int cur = 2;
    while (cur <= n) {
      	cur <<= 1;
        leftMost++;
    }

    // Power[i] is i to the 2^(2^1)th power mod MOD
	// Account for edge case of n = 1
    vector<long long> power(leftMost + 1);
    power[0] = 2;

    for (int i = 1; i <= leftMost; i++) {
      	power[i] = power[i - 1] * power[i - 1] % MOD;
    }

    long long result = 1;
    // Now multiply everything together
    for (int i = 0; i <= leftMost; i++) {
     	 if ((1 << i) & n) {
           	result *= power[i];
            result %= MOD;
        }
    }

    cout << result << endl;
    return 0;
}
