#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    // Each zero is a ten from the answer we can factor
    // We want to calculate the number of 10's we fac factor out
    // Each 10 can be factored in to 2 * 5
    // We know that there will be n/5 numbers divisible by 5
    // Out of each of those, 1/5 of them are divisible by 25
    // Out of each of those, 1/5 of them are divisible by 125
    // We know that there will be n/2 numbers divisible by 2
    // Repeat logic for 5, but notice that # of 5's > # of 2's

    int result = 0;

    n /= 5;
    while (n > 0) {
        result += n;
        n /= 5;
    }

    cout << result << endl;

    return 0;
}