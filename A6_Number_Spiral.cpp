#include <iostream>

using namespace std;

void solve() {
  	long long y, x;
    cin >> y >> x;

    // edge case
    if (x == 1 && y == 1) {
      	cout << 1 << endl;
        return;
    }

    // we can determine which "layer" we are on from max(x, y)
    // we define a layer to be y <= x = k or x <= y = k, or the backwards L shape, with equal leg lengths
    // if the layer number is odd, we start from left, otherwise, we start from top
    // notice that the end of each layer is layer ^ 2
    long long layer = max(x, y);

    // If the layer number is odd
    if (layer % 2 == 1) {
		// Check if we are on the horizontal part of the layer
        if (layer == y) {
         	// Our solution is layer - 1squared plus distance - 1
            cout << (layer - 1) * (layer - 1) + x << endl;
        }
        else {
         	// our solution is layer squared - y + 1
            cout << layer * layer - y + 1 << endl;
        }
    }
    else {
     	// Do what we did for odd, but flip x and y
    	if (layer == x) {
    		cout << (layer - 1) * (layer - 1) + y << endl;
    	}
    	else {
    		cout << layer * layer - x + 1 << endl;
    	}
    }
}

int main() {
	// Repeat the solution t times
	int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
      	solve();
    }

    return 0;
}