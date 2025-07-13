class Solution {
public:
    string processStr(string s) {
        string ans;
        for (auto i : s) {
            if (i >= 'a' && i <= 'z') {
                ans.push_back(i);
            } else {
                if (i == '*') {
                    if (ans.size() >= 1) {
                        ans.pop_back();
                    }
                } else if (i == '#') {
                    ans += ans;
                } else {
                    reverse(ans.begin(), ans.end());
                }
            }
        }
        return ans;
    }
};