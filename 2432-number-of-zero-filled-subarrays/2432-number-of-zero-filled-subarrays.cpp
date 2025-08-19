class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int sz = 0;
        for(auto i:nums){
            if(i==0){
                sz++;
            }
            else{
                ans+=(sz)*1LL*(sz+1)/2;
                sz=0;
            }
        }
        ans+=sz*1LL*(sz+1)/2;
        return ans;
    }
};