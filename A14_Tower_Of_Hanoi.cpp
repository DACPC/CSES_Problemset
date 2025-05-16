#include <vector>
#include <iostream>

using namespace std;

// Move top n discs from source to destination
void move(vector<vector<int>>& tower, int discs, int source, int destination) {
    // Base case
    if (discs == 1) {
    	cout << source + 1 << " " << destination + 1 << endl;
      	tower[destination].push_back(tower[source].back());
        tower[source].pop_back();
    	return;
    }
	// First, we need to move the top n - 1 discs to the spot next to destination
    move(tower, discs - 1, source, (~(source | destination)) & 3);
    // Now move the big disc
	cout << source + 1 << " " << destination + 1 << endl;
	tower[destination].push_back(tower[source].back());
	tower[source].pop_back();
    // Now move rest onto big disc
    move(tower, discs - 1, (~(source | destination)) & 3, destination);
}

int main() {
  	int n;
    cin >> n;

    // Construct towers
	vector<vector<int>> tower(3);
	for (int i = 0; i < 3; i++)
		tower[i].reserve(n);
	for (int i = 0; i < n; i++)
		tower[0].push_back(n - i);

    // 2 Steps:
    // Get into the following form:
    // biggest disc, all other discs, empty
    // Then move big disc over, and reverse everything in the opposite order
    //
    // In order to get that desired state, we have to first reach this state:
    // biggest 2 discs, empty, all other discs

	// It will take 2^n - 1 moves
	cout << (1 << n) - 1 << endl;
	move(tower, n, 0, 2);

	// for (const auto& t: tower)
	// 	cout << t.size() << endl;

  	return 0;
}