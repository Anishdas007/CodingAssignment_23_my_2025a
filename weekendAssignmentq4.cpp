#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.length() < t.length()) return "";

    unordered_map<char, int> need, window;
    for (char c : t) {
        need[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;
    int start = 0, minLen = INT_MAX;

    while (right < s.size()) {
        char c = s[right];
        right++;

        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) {
                valid++;
            }
        }

        while (valid == need.size()) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }

            char d = s[left];
            left++;

            if (need.count(d)) {
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << minWindow("a", "a") << endl;
    cout << minWindow("a", "aa") << endl;
    cout << minWindow("this is a test string", "tist") << endl;
    cout << minWindow("aaflslflsldkalskaaa", "aaa") << endl;
    return 0;
}
