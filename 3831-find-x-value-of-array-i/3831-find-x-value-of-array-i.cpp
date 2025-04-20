#define ll long long
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> dp(k,0);
        vector<ll> ans(k,0);
        for(int i=0;i<n;i++){
            vector<ll> ndp(k,0);
            ndp[nums[i]%k]++;
            for(int j=0;j<k;j++){
                ndp[(j*1LL*nums[i])%k]+=dp[j];
            }
            dp=ndp;
            for(int j=0;j<k;j++){
                ans[j]+=dp[j];
            }
        }
        return ans;

    }
};