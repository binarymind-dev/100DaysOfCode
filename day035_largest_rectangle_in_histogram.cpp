#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main() {
    Solution sol;

    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Test 1: " << sol.largestRectangleArea(heights1) << endl; 

    vector<int> heights2 = {2, 4};
    cout << "Test 2: " << sol.largestRectangleArea(heights2) << endl; 

    return 0;
}
