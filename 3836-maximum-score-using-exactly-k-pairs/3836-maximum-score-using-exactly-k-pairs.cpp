class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        const long long NEG = -1e18;

        vector<vector<vector<long long>>> dp(
            n+1,
            vector<vector<long long>>(m+1, vector<long long>(k+1, NEG))
        );

        // Base case: selecting 0 pairs gives 0 score
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                dp[i][j][0] = 0;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int x = 0; x <= k; x++) {

                    // Skip nums1
                    dp[i][j][x] = max(dp[i][j][x], dp[i-1][j][x]);

                    // Skip nums2
                    dp[i][j][x] = max(dp[i][j][x], dp[i][j-1][x]);

                    // Take pair
                    if(x > 0 && dp[i-1][j-1][x-1] != NEG) {
                        dp[i][j][x] = max(
                            dp[i][j][x],
                            dp[i-1][j-1][x-1] + 
                            1LL * nums1[i-1] * nums2[j-1]
                        );
                    }
                }
            }
        }

        return dp[n][m][k];
    }
};
