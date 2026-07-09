import java.util.*;

class Solution {

    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int q = queries.length;
        boolean[] ans = new boolean[q];
        int[] pref = new int[n];
        pref[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                pref[i]=pref[i-1];
            }
            else{
                pref[i]=i;
            }
        }
        for(int i=0;i<q;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] = (pref[u]==pref[v]?true:false);
        }
        return ans;
    }
}