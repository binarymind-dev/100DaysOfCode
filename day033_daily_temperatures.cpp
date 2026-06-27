#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // stores indices
        
        for (int i = 0; i < n; i++) {
            // While stack not empty and current temp > temp at stack top
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                result[idx] = i - idx; // days to wait
            }
            st.push(i);
        }
        
        return result;
    }
};
int main() {
    Solution sol;
    
    vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res1 = sol.dailyTemperatures(temps1);
    cout << "Output: ";
    for (int x : res1) cout << x << " ";
    cout << endl;
    
    vector<int> temps2 = {30, 40, 50, 60};
    vector<int> res2 = sol.dailyTemperatures(temps2);
    cout << "Output: ";
    for (int x : res2) cout << x << " ";
    cout << endl;
    
    vector<int> temps3 = {30, 60, 90};
    vector<int> res3 = sol.dailyTemperatures(temps3);
    cout << "Output: ";
    for (int x : res3) cout << x << " ";
    cout << endl;
   
    return 0;
}
