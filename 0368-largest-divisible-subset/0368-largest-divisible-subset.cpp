class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());  // Missing sorting step

        vector<int> dp(n, 1);
        vector<int> hash(n, -1);
        int maxi = 0, last = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && (1 + dp[j] > dp[i])) {  // Fixed condition
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                last = i;
            }
        }

        vector<int> ans;
        while (last != hash[last]) {
            ans.push_back(nums[last]);
            last = hash[last];
        }
        ans.push_back(nums[last]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
