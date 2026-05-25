#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;

    int left = 0, right = 0;
    int maxLength = 0;

    while (right < s.length()) {

        // If character not found, add it
        if (st.find(s[right]) == st.end()) {
            st.insert(s[right]);

            maxLength = max(maxLength, right - left + 1);

            right++;
        }
        else {
            // Remove left character
            st.erase(s[left]);
            left++;
        }
    }

    return maxLength;
}

int main() {

    string s = "abcabcbb";

    cout << "Longest Substring Length: "
         << lengthOfLongestSubstring(s);

    return 0;
}
