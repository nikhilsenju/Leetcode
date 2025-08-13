class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-2;
        int ans = 0;
        if(n==1){
            return 0;
        }
        while(hi>=lo){
            int mid = (hi+lo)>>1;
            if(nums[mid]>=nums[mid+1]){
                hi = mid-1;
            }
            else{
                 ans = mid+1;
                lo = mid+1;
            }
        }
        return ans;
    }

};