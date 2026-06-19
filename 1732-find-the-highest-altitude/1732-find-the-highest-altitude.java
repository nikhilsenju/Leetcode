import java.util.*;
class Solution {
    public int largestAltitude(int[] gain) {
        Integer maxi = 0;
        Integer sum = 0;
        Integer n = gain.length;
        for(int i=0;i<n;i++){
            sum+=gain[i];
            maxi = Math.max(sum,maxi);
        }
        return maxi;

    }
}