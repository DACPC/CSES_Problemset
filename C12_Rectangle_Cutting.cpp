#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  	int a, b;
    cin >> a >> b;

    // Slice the biggest square possible every time
    int result = 0;
    while (a != b) {
      	if (a > b)
          	a -= b;
        else
          	b -= a;
        result++;
    }

    cout << result;

    return 0;
}