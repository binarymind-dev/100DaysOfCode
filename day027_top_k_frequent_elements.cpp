#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        vector<int> result;
        for (int i = n; i >= 0 && (int)result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if ((int)result.size() == k) break;
            }
        }
 
        return result;
    }
};
 
int main(){
    Solution sol;
    {
        vector<int> nums = {1,1,1,2,2,3};
        int k = 2;
        auto res = sol.topKFrequent(nums, k);
        cout << "Result: ";
        for (int x : res) cout << x << " ";
        cout << "(expected 1 2, order may vary)\n";
    }
    {
        vector<int> nums = {1};
        int k = 1;
        auto res = sol.topKFrequent(nums, k);
        cout << "Result: ";
        for (int x : res) cout << x << " ";
        cout << "(expected 1)\n";
    }
    return 0;
}
 
