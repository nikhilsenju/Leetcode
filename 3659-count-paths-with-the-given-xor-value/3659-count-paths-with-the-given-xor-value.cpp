class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& v, int k) {
        int n = v.size();
        int m = v[0].size();
        int kk = k;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(40, -1)));
        int mod=1e9+7;
        function<int(int, int, int)> solve = [&](int i, int j, int curr) {
            if (i >= n || j >= m) {
                return 0;
            }
            curr = curr ^ v[i][j];
            if (i == n-1 && j == m-1) {
                return curr == kk ? 1 : 0;
            }
            if (dp[i][j][curr] != -1) {
                return dp[i][j][curr];
            }
            int up = 0;
            int left = 0;
            up = solve(i + 1, j, curr)%mod;
            left = solve(i, j + 1 ,curr)%mod;
            return dp[i][j][curr] = (up + left)%mod;
        };
        return solve(0,0,0);
    }
};