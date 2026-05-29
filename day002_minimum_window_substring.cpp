#include <iostream>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> need;
    for (char c : t) need[c]++;

    int missing = t.size(), left = 0, start = 0, minLen = INT_MAX;

    for (int right = 0; right < s.size(); right++) {
        if (need[s[right]] > 0) missing--;
        need[s[right]]--;

        if (missing == 0) {
            while (need[s[left]] < 0) {
                need[s[left]]++;
                left++;
            }
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            need[s[left]]++;
            missing++;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}