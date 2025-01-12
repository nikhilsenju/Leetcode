class Solution {
public:
    long long solve(int i, int j, int rem, vector<vector<int>>& v,
                    vector<vector<vector<long long>>>& dp) {
        if (i < 0 || j < 0)
            return INT_MIN;   
        if (i == 0 && j == 0) { 
            if (v[i][j] >= 0)
                return v[i][j];
            return (rem > 0) ? 0 : v[i][j]; 
        }
        if (dp[i][j][rem] != INT_MIN)
            return dp[i][j][rem];
        
        long long val = v[i][j]; 
        long long left = INT_MIN, up = INT_MIN;
        long long leftuse = INT_MIN, upused = INT_MIN;
        if (val >= 0) {
            left = val + solve(i, j - 1, rem, v, dp);
            up = val + solve(i - 1, j, rem, v, dp);
        } else {
            left = val + solve(i, j - 1, rem, v, dp);
            up = val + solve(i - 1, j, rem, v, dp);
        
            if (rem > 0) {
                leftuse = solve(i, j - 1, rem - 1, v, dp);
                upused = solve(i - 1, j, rem - 1, v, dp);
            }
        }
     
        return dp[i][j][rem] = max(max(left, up),max(leftuse, upused));
    }

    int maximumAmount(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(m, vector<long long>(3, INT_MIN)));
        return solve(n - 1, m - 1, 2, v, dp);
    }
};
