#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails; // tails[i] = smallest tail of all LIS of length i+1

        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);

            if (it == tails.end())
                tails.push_back(num);  // extend LIS
            else
                *it = num;             // replace to keep tails small
        }

        return tails.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS length: " << sol.lengthOfLIS(nums1) << "\n"; // 4

    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "LIS length: " << sol.lengthOfLIS(nums2) << "\n"; // 4

    vector<int> nums3 = {7, 7, 7, 7};
    cout << "LIS length: " << sol.lengthOfLIS(nums3) << "\n"; // 1

    return 0;
}
