class Solution {
public:
    int maxProfit(int kk, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(kk+1, 0)));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int k = 0; k <= kk; k++) {
                    if (k != 0) {
                        if (buy) {
                            dp[ind][buy][k] =
                                max(-prices[ind] + dp[ind + 1][!buy][k],
                                    dp[ind + 1][buy][k]);

                        } else {
                            dp[ind][buy][k] =
                                max(+prices[ind] + dp[ind + 1][!buy][k - 1],
                                    dp[ind + 1][buy][k]);
                        }
                    }
                }
            }
        }
        return dp[0][1][kk];
    }
};