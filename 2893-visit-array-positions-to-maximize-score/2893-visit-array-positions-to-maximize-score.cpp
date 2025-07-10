class Solution {
public:
    unordered_map<long long, long long> dp; // key = (index << 1) | parity

    long long solve(int ind, int p, vector<int>& v, int x) {
        if (ind >= v.size()) return 0;

        long long key = ((long long)ind << 1) | p;
        if (dp.count(key)) return dp[key];

        int cur = ((v[ind] % 2) == p) ? v[ind] : 0;
        long long change = -x + solve(ind + 1, !p, v, x) + cur;
        long long nott = solve(ind + 1, p, v, x) + cur;

        return dp[key] = max(change, nott);
    }

    long long maxScore(vector<int>& nums, int x) {
        return solve(0, nums[0] % 2, nums, x);
    }
};
