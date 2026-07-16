class Solution {
    static int gcd(int a,int b){
        int tmp1 = Math.max(a,b);
        int tmp2 = Math.min(a,b);
        a = tmp1;
        b = tmp2;
        while(b!=0){
            int tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }
    public long gcdSum(int[] nums) {
        int n = nums.length;
        int[] pref = new int[n];
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = Math.max(mx,nums[i]);
            pref[i]=gcd(mx,nums[i]);
        }
        Arrays.sort(pref);
        long sum = 0;
        for(int i=0;i<n/2;i++){
            sum+=gcd(pref[i],pref[n-i-1]);
        }
        return sum;

    }
}