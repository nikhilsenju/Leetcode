class Solution {
    final int MOD = 1000000007;

    public int[] sumAndMultiply(String s, int[][] queries) {
        int n = s.length();
        char[] arr = s.toCharArray();

        int[] pow = new int[n + 1];
        int[] pref = new int[n + 1];
        int[] subs = new int[n + 1];
        int[] cnt = new int[n + 1];

        pow[0] = 1;
        pref[0] = 0;
        subs[0] = 0;

        for (int i = 0; i < n; i++) {
            int d = arr[i] - '0';

            // Correct computation of powers of 10
            pow[i + 1] = (int) ((long) pow[i] * 10 % MOD);

            // Prefix sum of digits
            pref[i + 1] = pref[i] + d;

            // Prefix number ignoring zeros
            if (d > 0) {
                subs[i + 1] = (int) (((long) subs[i] * 10 + d) % MOD);
            } else {
                subs[i + 1] = subs[i];
            }

            cnt[i + 1] = cnt[i] + (d > 0 ? 1 : 0);
        }

        int m = queries.length;
        int[] ans = new int[m];

        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;

            int len = cnt[r] - cnt[l];

            int a = (int) ((subs[r] - ((long) subs[l] * pow[len]) % MOD + MOD) % MOD);

            long sumi = pref[r] - pref[l];

            ans[i] = (int) ((a * sumi) % MOD);
        }

        return ans;
    }
}