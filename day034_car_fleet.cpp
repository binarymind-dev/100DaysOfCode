#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);
        
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), greater<pair<int,int>>());
        
        stack<double> st;
        
        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;

            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        
        return st.size();
    }
};
int main() {
    Solution sol;

    vector<int> pos1 = {10, 8, 0, 5, 3};
    vector<int> spd1 = {2, 4, 1, 1, 3};
    cout << "Test 1: " << sol.carFleet(12, pos1, spd1) << endl;
    vector<int> pos2 = {3};
    vector<int> spd2 = {3};
    cout << "Test 2: " << sol.carFleet(10, pos2, spd2) << endl;
    vector<int> pos3 = {0, 4, 2};
    vector<int> spd3 = {2, 1, 3};
    cout << "Test 3: " << sol.carFleet(10, pos3, spd3) << endl;

    return 0;
}
