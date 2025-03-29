class Solution {
public:
   void f(int ind, int tar, vector<int>& c, vector<int>& ds, set<vector<int>>& st) {
       // Base case: if we have reached the end of the array
       if (ind == c.size()) {
           if (tar == 0) {
               st.insert(ds);
           }
           return;  // Exit the function to prevent further execution
       }

       // Choose the current element if it's less than or equal to the target
       if (c[ind] <= tar) {
           ds.push_back(c[ind]);
           f(ind, tar - c[ind], c, ds, st);  // Recursive call with the same index
           ds.pop_back();  // Backtrack
       }

       // Skip the current element and move to the next
       f(ind + 1, tar, c, ds, st);
   }

   vector<vector<int>> combinationSum(vector<int>& c, int t) {
       sort(c.begin(), c.end());
       vector<vector<int>> ans;
       set<vector<int>> st;
       vector<int> ds;
       f(0, t, c, ds, st);
       for (auto& i : st) {
           ans.push_back(i);
       }
       return ans;
   }
};
