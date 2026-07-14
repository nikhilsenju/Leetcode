class Solution {
public:
    static const int MOD = 1000000007;
    int dp[205][205][205];
    int n;

    int solve(int ind, int gcd1, int gcd2, vector<int>& nums) {
        // Base case
        if (ind == n) {
            if (gcd1 == 0 || gcd2 == 0)
                return 0;
            return gcd1 == gcd2;
        }

        if (dp[ind][gcd1][gcd2] != -1)
            return dp[ind][gcd1][gcd2];

        long long ans = 0;

        // Put nums[ind] in first subsequence
        ans += solve(ind + 1, std::gcd(gcd1, nums[ind]), gcd2, nums);
        ans %= MOD;

        // Put nums[ind] in second subsequence
        ans += solve(ind + 1, gcd1, std::gcd(gcd2, nums[ind]), nums);
        ans %= MOD;

        // Skip nums[ind]
        ans += solve(ind + 1, gcd1, gcd2, nums);
        ans %= MOD;

        return dp[ind][gcd1][gcd2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};