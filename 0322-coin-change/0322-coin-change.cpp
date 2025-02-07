class Solution {
public:
    int f(int ind, int tar, vector<int>& v, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (tar % v[0] == 0) return tar / v[0];
            return 1e9;
        }
        if (dp[ind][tar] != -1) return dp[ind][tar];

        int take = 1e9;
        if (tar >= v[ind]) {
            take = 1 + f(ind, tar - v[ind], v, dp);
        }
        int notake = f(ind - 1, tar, v, dp);

        return dp[ind][tar] = min(take, notake);
    }

    int coinChange(vector<int>& v, int tar) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        int ans = f(n - 1, tar, v, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
