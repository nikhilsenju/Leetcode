class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(hi>=lo){
            int mid = (hi+lo)>>1;
            if(nums[mid]==target){
                return true;
            }
            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
                lo++;
                hi--;
                continue;
            }
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && nums[mid]>=target){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if(nums[mid]<=target && nums[hi]>=target){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }

            }
        }
        return false;
    }
};