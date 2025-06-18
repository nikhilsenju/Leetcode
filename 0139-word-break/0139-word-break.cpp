class Solution {
public:
    bool isInset(string& s, int first, int last, unordered_set<string>& st) {
        string sub = s.substr(first, last - first + 1);
        return st.count(sub);
    }

    bool solve(int ind, string &s, unordered_set<string>& st, unordered_map<int, bool>& dp) {
        if (ind == s.size()) return true;
        if (dp.count(ind)) return dp[ind];

        for (int i = ind; i < s.size(); i++) {
            if (isInset(s, ind, i, st)) {
                if (solve(i + 1, s, st, dp)) {
                    return dp[ind] = true;
                }
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wd) {
        unordered_set<string> st(wd.begin(), wd.end());
        unordered_map<int, bool> dp;
        return solve(0, s, st, dp);
    }   
};
