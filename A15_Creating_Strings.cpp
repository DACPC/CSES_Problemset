#include <iostream>
#include <string>
#include <vector>

using namespace std;

void createString(vector<int>& freq, string current, const int n) {
  	if (current.size() == n)
        cout << current << endl;

    for (char c = 'a'; c <= 'z'; c++) {
      	if (!freq[c - 'a'])
          	continue;
        freq[c - 'a']--;
        createString(freq, current + c, n);
        freq[c - 'a']++;
    }
}
int main() {
  	string s;
    cin >> s;

    int n = s.size();

    // Number of combinations will be: n! / number of duplicates!
    vector<int> freq(26, 0);
    for (char c: s)
      	freq[c - 'a']++;
    int result = 1;
    for (int i = 2; i <= n; i++)
      	result *= i;
    for (int count: freq)
      	for (int i = 2; i <= count; i++)
          	result /= i;
    cout << result << endl;

    // Now use recursion to create strings one character at a time
    createString(freq, "", n);

    return 0;
}