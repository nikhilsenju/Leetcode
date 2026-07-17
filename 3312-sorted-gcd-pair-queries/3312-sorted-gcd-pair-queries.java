class Solution {
    public int[] gcdValues(int[] nums, long[] queries) {
        int n = nums.length;
        int m = queries.length;
        int mx = 0;
        for(int i=0;i<n;i++){mx = Math.max(mx,nums[i]);}
        int[] freq = new int[mx+1];
        int[] cnt = new int[mx+1];
        long[] nopd = new long[mx+1];
        long[] egcd = new long[mx+1];
        int[] gcd = new int[m];
        for(int i=0;i<n;i++){freq[nums[i]]++;}
        for(int i=1;i<=mx;i++){
            for(int j=i;j<=mx;j+=i){
                cnt[i]+=freq[j];
            }
        }
        for(int i=mx;i>=1;i--){
            long p = (long)cnt[i]*(cnt[i]-1)/2;
            egcd[i]=p;
            for(int j=2*i;j<=mx;j+=i){
                egcd[i]-=egcd[j];
            }
        }
        for(int i=2;i<=mx;i++){
            egcd[i]+=egcd[i-1];
        }
        for(int i=0;i<m;i++){
            long q = queries[i];
            int lo = 1;
            int hi = mx;
            int ans = -1;
            while(hi>=lo){
                int mid = (hi+lo)/2;
                if(egcd[mid]>q){
                    ans = mid;
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            gcd[i]=ans;

        }
        return gcd;
        


    }
}