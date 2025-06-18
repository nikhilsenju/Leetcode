class Solution {
public:
    void solve(int ind, string &num, int target, string path, long long curr, long long prev, vector<string>& ans) {
        if (ind == num.size()) {
            if (curr == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = ind; i < num.size(); i++) {
            if (i > ind && num[ind] == '0') break; // leading zero check

            string tmp = num.substr(ind, i - ind + 1);
            long long val = stoll(tmp);

            if (ind == 0) {
                // first number, no operator
                solve(i + 1, num, target, tmp, val, val, ans);
            } else {
                solve(i + 1, num, target, path + "+" + tmp, curr + val, val, ans);
                solve(i + 1, num, target, path + "-" + tmp, curr - val, -val, ans);
                solve(i + 1, num, target, path + "*" + tmp, curr - prev + prev * val, prev * val, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, num, target, "", 0, 0, ans);
        return ans;
    }
};
