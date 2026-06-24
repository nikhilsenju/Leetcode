class Solution {
    public int zigZagArrays(int n, int l, int r) {
        int MOD = 1000000007;
        int m = r-l+1;
        int[]dp0 = new int[m+1];
        int[]dp1 = new int[m+1];
        int[]sum0 = new int[m+1];
        int[]sum1 = new int[m+1];
        for(int i=0;i<=m;i++){
            dp0[i]=0;dp1[i]=0;sum0[i]=0;sum1[i]=0;
        }
        for(int i=0;i<m;i++){
            dp1[i]=1;
            dp0[i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                sum0[j+1]=(sum0[j]+dp0[j])%MOD;
                sum1[j+1]=(sum1[j]+dp1[j])%MOD;
            }
            for(int j=0;j<m;j++){
                dp0[j]=(sum1[m]-sum1[j+1]+MOD)%MOD;
                dp1[j]=(sum0[j]);
            }
        }
        int ans0 = 0;
        int ans1 = 0;
        for(int i=0;i<m;i++){
            ans1=(ans1+dp1[i])%MOD;
            ans0=(ans0+dp0[i])%MOD;
        }
        return (ans1+ans0)%MOD;
    }
}