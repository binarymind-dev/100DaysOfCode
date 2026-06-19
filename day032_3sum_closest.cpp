#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // initialize with first triplet
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                if (currentSum == target) {
                    return currentSum; // can't get closer than exact match
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << sol.threeSumClosest(nums, target) << endl; // Expected output: 2
    
    return 0;
}
