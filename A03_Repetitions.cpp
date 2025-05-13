#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    // result will be the length of the longest substring of repeating numbers
    int result = 0;
    // the length of the current substring of repeating numbers
    int current = 0;
    // the last character
    char last = 0;
    // check every character in input
    for (char c : s) {
        // If the character is a repeat, add to current
        if (c == last) {
            current++;
        }
        // otherwise, update result and last, and reset current to 1
        else {
            last = c;
            result = max(result, current);
            current = 1;
        }
    }
    // Take the max one last time if substring reaches the end
    result = max(result, current);

    cout << result;

    return 0;
}
