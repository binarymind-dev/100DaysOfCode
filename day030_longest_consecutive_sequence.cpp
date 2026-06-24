#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Only start counting if 'num' is the beginning of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                int current = num;

                while (numSet.find(current + 1) != numSet.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << "Longest Consecutive Sequence Length: "
         << sol.longestConsecutive(nums) << endl;

    return 0;
}
