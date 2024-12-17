class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
      
        long long val=1e18;
        vector<long long> v(k,val);
        long long ans = -1e18;
        long long cursum=0;
        v[k-1]=0;

        for(long long i=0;i<nums.size();i++){
            cursum+=nums[i];
            if(i>=k-1){
                ans=max(ans,cursum-v[i%k]);
            }
            v[i%k]=min(v[i%k],cursum);
        }
        return ans;
    
        
    }
};