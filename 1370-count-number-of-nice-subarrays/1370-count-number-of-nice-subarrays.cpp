class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n = nums.size();
        int i=0;
        int j=0;
        int ans=0;
        int c=0;
        while(j<n){
            c+=(nums[j]&1);
            while(c>k){
                c-=(nums[i]&1);
                i++;
            }
            ans+=j-i+1;
            j++;
            
        }
        return ans;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);

        
    }
};