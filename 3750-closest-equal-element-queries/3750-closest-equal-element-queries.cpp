class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& q) {
        int n = nums.size();
        map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int x : q) {
            if (mp.find(nums[x]) == mp.end() || mp[nums[x]].size() == 1) {
                ans.push_back(-1);
                continue;
            }

            vector<int>& v = mp[nums[x]];
            int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
            if(idx==0){
                int d = abs(n+v[idx]-v.back());
                ans.push_back(min(d,v[idx+1]-v[idx]));

            }
            else if(idx==v.size()-1){
                int d = abs(n-v[idx]+v[0]);
                ans.push_back(min(d,v[idx]-v[idx-1]));

            }
            else{
                ans.push_back(min(abs(v[idx]-v[idx-1]),abs(v[idx]-v[idx+1])));

            }
        }

        return ans;
    }
};
