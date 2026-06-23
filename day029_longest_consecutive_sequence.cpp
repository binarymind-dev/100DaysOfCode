#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Only start counting from the beginning of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums1) << endl;

    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longestConsecutive(nums2) << endl; 

    vector<int> nums3 = {};
    cout << sol.longestConsecutive(nums3) << endl; 

    vector<int> nums4 = {1};
    cout << sol.longestConsecutive(nums4) << endl;

    vector<int> nums5 = {1, 2, 0, 1};
    cout << sol.longestConsecutive(nums5) << endl; 

    return 0;
}
