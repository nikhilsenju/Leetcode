class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        sort(nums.begin(),nums.end());
        int maxi = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]-maxi>k){
                ans++;
                maxi = nums[i];
            }
        }
        return ans;
        
        
    }
};