#include <iostream>

using namespace std;

int main() {
	int n;
    cin >> n;

    /*
	There are (n * n) Choose 2 ways for 2 horses to be on the board
	This simplifies to P = (n * n)((n * n - 1)/2 ways
	The number of ways to put 2 knights on the board without attacking each other is the same as:
	The number of ways to not put 2 knights on the board that attack each other, in other words,
	P - ways to put 2 knights on the board that attack each other
	Our question now befomes: how many ways are there to put 2 knights on the board that attack each other?
     */

    /*
	Let's consider 4 cases:
	1. The knight is on a corner, and can only attack knights 2 tiles
	2. The knight is on an edge next to the corner, and can only attack 3 tiles
	3a. The knight is on an edge not near a corner, and can attack 4 tiles
	3b. The knight is one diagonal away from the corner, and can attack 4 tiles
	4. The knight is one move away from the edge, excluding 3b, and can attack 6 tiles
	5. The knight is not on an edge, and can attack 8 tiles

	For n >= 4
	There are 4 spots on the board where case 1 occurs
	There are 8 spots on the board where case 2 occurs
	There are (4 * n) - 4 - 8 - 4 + 4 spots on the board where case 3 occurs (4*n)-4 is number of edges, -4-8 for case 1 and 2, +4 cor case 3b
	There are 4 * (n - 2) - 4 - 4 spots on the board where case 4 occurs (4*(n-2))-4 is number of edge-adjacents, -4 for case 3b
	There are (n - 4) * (n - 4) spots on the board where case 5 occurs

	Multiply the amount of spots by the number of tiles they attack, then divide by two since everything will be doubled
	Then subtract that from the total number of permutations
     */

    // Since our rule applies for n >= 4, we will hard-code the first 3 cases
    cout << 0 << endl;
    if (n == 1)
      return 0;
	cout << 6 << endl;
	if (n == 2)
		return 0;
	cout << 28 << endl;
	if (n == 3)
		return 0;

    // Now we can use our rule for the rest of the test caes
    for (long long i = 4; i <= n; i++) {
      	// Total number of ways for two knights to be on the board
      	long long totalWays = (i * i) * (i * i - 1) / 2;

        // Total number of ways for 2 knights to attack each other
        // First two cases will always add up to 32
     //    long long attackWays = 32;
     //    attackWays += ((4 * i) - 12) * 4;
    	// attackWays += (4 * (i - 2) - 8) * 6;
     //    attackWays += ((i - 4) * (i - 4)) * 8;
     //
    	// long long solution = totalWays - (attackWays / 2);
     //
     //    cout << solution << endl;

    	// The previous code simplifies to the following:
    	cout << totalWays - (8 - i * 12 + i * i * 4) << endl;
    }

    return 0;
}