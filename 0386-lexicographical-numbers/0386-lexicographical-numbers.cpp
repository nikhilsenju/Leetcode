class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            ans.push_back(to_string(i));
        }

        sort(ans.begin(), ans.end());  // simple lexicographical sort

        vector<int> res;
        for (const string& s : ans) {
            res.push_back(stoi(s));
        }

        return res;
    }
};
