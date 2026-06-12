#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;

    vector<int> coins1 = {1, 5, 10};
    cout << sol.coinChange(coins1, 11) << "\n"; // Output: 2

    vector<int> coins2 = {2};
    cout << sol.coinChange(coins2, 3) << "\n";  // Output: -1

    return 0;
}
