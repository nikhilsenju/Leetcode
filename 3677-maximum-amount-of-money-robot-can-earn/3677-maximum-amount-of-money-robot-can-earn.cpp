class Solution {
public:
    long long solve(int i, int j, int rem, vector<vector<int>>& v,
                    vector<vector<vector<long long>>>& dp) {
        if (i < 0 || j < 0) {
            return INT_MIN;  // Out of bounds, return 0
        }
        if (i == 0 && j == 0) {  // Base case: top-left corner
            if (v[i][j] >= 0)
                return v[i][j];
            return (rem > 0) ? 0 : v[i][j];  // If negative, either return 0 or value based on remaining flips
        }
        if (dp[i][j][rem] != INT_MIN) {
            return dp[i][j][rem];  // Return already computed value
        }

        // If the current cell is positive, simply add it to the best path
        long long useLeft = INT_MIN;
        long long useUp = INT_MIN;
        long long left =INT_MIN; 
        long long up =INT_MIN;
        long long val=v[i][j];
        if (val >= 0) {
             left = val + solve(i, j - 1, rem, v, dp);
             up = val + solve(i - 1, j, rem, v, dp);
        } else {
            // If the current cell is negative, we can either move without using flips or use a flip
             left = val + solve(i, j - 1, rem, v, dp);
             up = val + solve(i - 1, j, rem, v, dp);
            
            // If flips are still available, we try using them to skip negative cells
            if (rem > 0) {
                useLeft = solve(i, j - 1, rem - 1, v, dp);
                useUp = solve(i - 1, j, rem - 1, v, dp);
            }

            // Max of all possible choices
        }
         return dp[i][j][rem] = max(max(left,up),max(useLeft,useUp)); 
    }

    int maximumAmount(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(m, vector<long long>(3, INT_MIN)));  // Memoization table for each state
        return solve(n - 1, m - 1, 2, v, dp);  // Start solving from bottom-right corner with 2 flips remaining
    }
};
