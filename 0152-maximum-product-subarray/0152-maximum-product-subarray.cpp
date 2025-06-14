class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxi = nums[0];
        int mini = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0){
                maxi = 1;
                mini = 1;
                res=max(res,0);
                continue;
            }
            int temp = maxi;
            maxi = max({temp*nums[i],mini*nums[i],nums[i]});
            mini = min({temp*nums[i],mini*nums[i],nums[i]});
            res = max({res,maxi,mini});
        }
        return res;
    }
};