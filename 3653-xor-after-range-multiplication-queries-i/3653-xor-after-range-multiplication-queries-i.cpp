const int mod = 1e9+7;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int ans = 0;
        
        for(auto i:q){
            auto vec = i;
            int l = vec[0];
            int r = vec[1];
            int inc = vec[2];
            int val = vec[3];
            for(int j=l;j<=r;j+=inc){
                nums[j]=(nums[j]*1LL*val)%(mod);
            }
        }
        for(auto i:nums){
            ans^=i;
        }
        return ans;
    }

};