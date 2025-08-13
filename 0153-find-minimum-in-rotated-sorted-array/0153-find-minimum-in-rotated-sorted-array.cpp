class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int mini = INT_MAX;
        while(hi>=lo){
            int mid = (hi+lo)>>1;
            if(nums[lo]<=nums[mid]){
                mini = min(mini,nums[lo]);
                lo = mid+1;
            }
            else{
                mini = min(mini,nums[mid]);
                hi = mid-1;
            }
        }
        return mini;
    }
};