#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;


    vector<int> freq(26, 0);

    for (char c: s) {
        freq[c - 'A']++;
    }

    int oddCount = 0;
    for (int count: freq)
      	if (count & 1)
          	oddCount++;
    if (oddCount > 1) {
      	cout << "NO SOLUTION" << endl;
        return 0;
    }


    string output;
    char oddChar;
    for (int i = 0; i < 26; i++) {
      	for (int j = 0; j < freq[i] >> 1; j++)
          	output += (char)('A' + i);
        if (freq[i] & 1)
          	oddChar = (char)('A' + i);
    }


    if (oddCount)
      	output += oddChar;

	for (int i = 25; i >= 0; i--) {
		for (int j = 0; j < freq[i] >> 1; j++)
			output += (char)('A' + i);
		if (freq[i] & 1)
			oddChar = (char)('A' + i);
	}

    cout << output << endl;

    return 0;
}