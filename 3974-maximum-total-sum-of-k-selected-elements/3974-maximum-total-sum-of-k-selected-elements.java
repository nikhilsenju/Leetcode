import java.util.*;
class Solution {
    public long maxSum(int[] nums, int k, int mul) {
        Arrays.sort(nums);
        long ans = 0;
        int n = nums.length;
        for(int i=n-1;i>=0 && k>0;i--){
            if(mul>=1){
                if(nums[i]>=0){
                    ans+=nums[i]*1L*mul;
                }
                else{
                    ans+=nums[i];
                }
            }
            else{
                if(nums[i]>=0){
                    ans+=nums[i];
                }
                else{
                    ans+=nums[i]*1L*mul;
                }
            }
            mul--;
            k--;
        }
        return ans;
    }
}