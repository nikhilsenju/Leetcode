class Solution {
    static final int mod = 1000000007;
    public int xorAfterQueries(int[] nums, int[][] q) {
        int n = nums.length;
        int ans = 0;
        for(int[] vec : q){
            int l = vec[0];
            int r = vec[1];
            int k = vec[2];
            int v = vec[3];
            for(int i=l;i<=r;i+=k){
                nums[i]=(int)((nums[i]*1L*v)%mod);
            }
        }
        for(int i : nums){
            ans^=i;
        }
        return ans;
    }

}