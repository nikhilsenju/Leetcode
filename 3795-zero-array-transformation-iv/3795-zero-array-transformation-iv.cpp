class Solution {
public:
    bool cansolve(vector<int>& nums, int ind, int tar, vector<vector<int>>& dp) {
        if (tar == 0) return true;
        if (ind == 0) return nums[ind] == tar;
        if (dp[ind][tar] != -1) return dp[ind][tar];

        bool nt = cansolve(nums, ind - 1, tar, dp);
        bool tt = false;
        if (tar >= nums[ind]) {
            tt = cansolve(nums, ind - 1, tar - nums[ind], dp);
        }
        return dp[ind][tar] = tt || nt;
    }

    bool solve(int k, vector<vector<int>>& q, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> vp(n + 1);

        for (int i = 0; i <= k; i++) {
            int st = q[i][0], en = q[i][1], val = q[i][2];
            for (int j = st; j <= en; j++) {
                vp[j].push_back(val);
            }
        }
        cout<<k<<endl;
        for(int i=0;i<n;i++){
            cout<<i<<" ";
            for(auto j:vp[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }

        for (int i = 0; i < n; i++) {
            if(vp[i].empty()){
                if(v[i]!=0){
                    return false;
                }
            }
            if (!vp[i].empty()) { // Process non-empty vectors
                int sumTarget = v[i];
                vector<vector<int>> dp(vp[i].size(), vector<int>(sumTarget + 1, -1));
                if (!cansolve(vp[i], vp[i].size() - 1, sumTarget, dp)) {
                    return false;
                }
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size(), m = q.size();
        int lo = 0, hi = m - 1, ans = -1;
        int sum=0;
        for(auto i:v){
            sum+=i;
        
        }
        if(!sum){
            return 0;
        }

        while (hi >= lo) {
            int mid = (hi + lo) / 2;
            if (solve(mid, q, v)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans==-1?-1:ans+1;
    }
};
