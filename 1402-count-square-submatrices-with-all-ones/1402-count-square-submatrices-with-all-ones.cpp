class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Copy mat into dp with 1-based indexing
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i+1][j+1] = mat[i][j];
            }
        }

        // Row-wise prefix
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] += dp[i][j-1];
            }
        }

        // Column-wise prefix
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                dp[i][j] += dp[i-1][j];
            }
        }

        int ans = 0;
        int kk = min(n, m);

        // Check all possible squares
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= kk && i+k-1 <= n && j+k-1 <= m; k++) {
                    int r1 = i, c1 = j;
                    int r2 = i + k - 1, c2 = j + k - 1;

                    // Correct submatrix sum formula
                    int pres = dp[r2][c2]
                             - dp[r1-1][c2]
                             - dp[r2][c1-1]
                             + dp[r1-1][c1-1];

                    if (pres == k * k) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
