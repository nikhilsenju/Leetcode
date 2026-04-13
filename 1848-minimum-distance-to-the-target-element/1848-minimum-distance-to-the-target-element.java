import java.util.*;
class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int n = nums.length;
        int mini = Integer.MAX_VALUE;
        for(int i = 0 ; i < n ; i++){
            if(target==nums[i]){
                mini = Math.min(mini,Math.abs(i-start));
            }
        }
        return mini;
    }
}