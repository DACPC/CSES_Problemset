#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

// Check if this square is being attacked
bool isValid(vector<string>& board, int row, int col) {
  	// Check in + shape
  	for (int i = 0; i < 8; i++) {
        // Check row
        if (i != col && board[row][i] == 'Q')
          	return false;
  		// Check col
  		if (i != row && board[i][col] == 'Q')
  			return false;
  	}
    // Check the \ diagonal
    for (int i = row - col, j = 0; i < 8 && j < 8; i++, j++)
      	if (i >= 0 && i != row && j != col && board[i][j] == 'Q')
          	return false;
   	// Check the / diagonal
    for (int i = row + col, j = 0; i >= 0 && j < 8; i--, j++)
    	if (i < 8 && i != row && j != col && board[i][j] == 'Q')
    		return false;

    return true;
}

ll getWays(vector<string>& board, int row) {
  	// Try all the possibilities of positions for queens this row
    // For each tile, we check whether it is valid (no queens attackign it)
    // Then we place a queen there, and recurese downwards
    // Return the sum of possibilities from each position

    // Base case: we're past the last row
    if (row == 8)
      	return 1;

    ll result = 0;
    for (int i = 0; i < 8; i++) {
      	if (board[row][i] == '*' || !isValid(board, row, i))
          	continue;
        board[row][i] = 'Q';
        result += getWays(board, row + 1);
        board[row][i] = '.';
    }

    return result;
}

int main() {
  	vector<string> board(8);
    for (int i = 0; i < 8; i++)
      	cin >> board[i];

    // Use recursion to brute-force the answer
    // Rather than to brute-force tile-by-tile, we will do it row-by-row
    cout << getWays(board, 0) << endl;

    return 0;
}