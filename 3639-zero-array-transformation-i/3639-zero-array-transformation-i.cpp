class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> vp(n+1,0);
        for(auto i:q){
            int l = i[0];
            int r = i[1];
            vp[l]++;
            vp[r+1]--;
        }
        for(int i=1;i<=n;i++){
            vp[i]+=vp[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>vp[i]){
                return false;
            }
        }
        return true;
    }
};