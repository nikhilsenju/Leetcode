class Solution {
public:
    void f(int ind, int tar, vector<int>& tmp, vector<int>& v, vector<vector<int>>& ans) {
        if (tar == 0) { // Base condition
            ans.push_back(tmp);
            return;
        }

        for (int i = ind; i < v.size(); i++) {
            if (i > ind && v[i] == v[i - 1]) continue; // Skip duplicates
            if (v[i] > tar) break; // Stop if current element is greater than target
            
            tmp.push_back(v[i]);
            f(i + 1, tar - v[i], tmp, v, ans);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        f(0, k, tmp, v, ans);
        return ans;
    }
};
