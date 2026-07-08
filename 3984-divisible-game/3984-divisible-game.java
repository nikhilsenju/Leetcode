import java.util.*;
class Solution {
    static long check(int k,int[] nums){
        int n = nums.length;
        int res = (nums[0]%k==0?nums[0]:-nums[0]);
        int maxE = res;
        for(int i=1;i<n;i++){
            int cur = (nums[i]%k==0?nums[i]:-nums[i]);
            maxE = Math.max(maxE+cur,cur);
            res = Math.max(res,maxE);
        }
        return res;
    }
    static int MOD = 1000000007;
    public int divisibleGame(int[] nums) {
        int n = nums.length;
        HashSet<Integer> st = new HashSet<>();
        for(int i=0;i<n;i++){
            int x = nums[i];
            for(int j=1;j*j<=x;j++){
                if(x%j!=0){continue;}
                st.add(j);
                st.add(x/j);
            }
        }
        if(st.contains(1)){
            st.remove(1);
        }
        st.add(2);
        ArrayList<Integer> v = new ArrayList<>();
        for(int x:st){
            v.add(x);
        }
        Collections.sort(v);
        long score = Integer.MIN_VALUE;
        long kk = -1;
        for(int k:v){
            long curs = check(k,nums);
            if(curs>score){
                score = curs;
                kk = k;
            }
        }
        int ans = (int)((score+MOD)%MOD*kk%MOD)%MOD;
        return ans;
        


    }
}