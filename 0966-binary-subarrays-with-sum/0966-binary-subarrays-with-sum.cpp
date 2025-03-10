class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n = nums.size();
        int i =0;
        int j =0;
        int ans =0;
        int c=0;
        while(i<n && j<n){
            c+=nums[j];
            while(j>=i && c>k){
                c-=nums[i];
                i++;
            }
            ans+=max(0,j-i+1);
            j++;

        }
        return ans;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {  
        return solve(nums,goal)-solve(nums,goal-1);    
    }
};