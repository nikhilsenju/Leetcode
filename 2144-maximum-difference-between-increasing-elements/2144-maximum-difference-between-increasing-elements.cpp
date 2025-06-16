class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            int maxi = 0;
            for(int j=i+1;j<n;j++){
                maxi = max(maxi,nums[j]);
            }
            if(maxi>nums[i]){
                ans = max(ans,maxi-nums[i]);
            }
        }   
        return ans;
    }
};