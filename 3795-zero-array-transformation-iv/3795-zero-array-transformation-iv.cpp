class Solution {
public:
    vector<vector<int>> dp ;
    bool poss1(vector<int>& v, int i, int t) {
        if (t == 0)
            return true;
        if (t < 0)
            return false;
        if (i >= v.size())
            return false;
        if (dp[i][t] != -1)
            return dp[i][t];

        return (dp[i][t] =
                    (poss1(v, i + 1, t) || poss1(v, i + 1, t - v[i])));
    }

    bool solve(int k, vector<vector<int>>& q, vector<int>& v) {
        for (int i = 0; i < v.size(); i++) {
            vector<int> tmp;
            for (int j = 0; j < k; j++) {
                if (i >= q[j][0] && i <= q[j][1]) {
                    tmp.push_back(q[j][2]);
                }
            }
            dp.clear();
            dp.resize(tmp.size(), vector<int>(1e4 + 10, -1));
            if (!poss1(tmp, 0, v[i])) {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size(), m = q.size();
        int lo = 0, hi = m, ans =m+10;

        while (hi >= lo) {
            int mid = (hi + lo) / 2;
            if (solve(mid, q, v)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans<=m?ans:-1;
    }
};
