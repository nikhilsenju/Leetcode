class Solution {

    static class RollingHash {
        static final long MOD = 1_000_000_007L;
        static final long BASE = 911382323L;

        long[] hash;
        long[] power;

        RollingHash(int[] arr) {
            int n = arr.length;

            hash = new long[n + 1];
            power = new long[n + 1];

            power[0] = 1;

            for (int i = 0; i < n; i++) {
                power[i + 1] = (power[i] * BASE) % MOD;
                hash[i + 1] = (hash[i] * BASE + arr[i] + 1) % MOD;
            }
        }

        long getHash(int l, int r) {
            if (l > r)
                return 0;

            long ans = hash[r + 1] - (hash[l] * power[r - l + 1]) % MOD;
            if (ans < 0)
                ans += MOD;
            return ans;
        }
    }

    static int maxodd(int c, RollingHash h1, RollingHash h2, int n) {

        int lo = 1;
        int hi = Math.min(c + 1, n - c);

        int maxvalid = -1;

        while (lo <= hi) {

            int mid = (lo + hi) / 2;

            int l = c - mid + 1;
            int r = c + mid - 1;

            int rl = n - 1 - r;
            int rr = n - 1 - l;

            if (h1.getHash(l, r) == h2.getHash(rl, rr)) {
                maxvalid = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return maxvalid;
    }

    static int maxeven(int c, RollingHash h1, RollingHash h2, int n) {

        int lo = 1;
        int hi = Math.min(c + 1, n - c - 1);

        int maxvalid = -1;

        while (lo <= hi) {

            int mid = (lo + hi) / 2;

            int l = c - mid + 1;
            int r = c + mid;

            int rl = n - 1 - r;
            int rr = n - 1 - l;

            if (h1.getHash(l, r) == h2.getHash(rl, rr)) {
                maxvalid = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return maxvalid;
    }

    public long getSum(int[] arr) {

        int n = arr.length;

        long ans = Long.MIN_VALUE;

        int[] revArr = new int[n];
        long[] pref = new long[n + 1];

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
            revArr[i] = arr[n - 1 - i];
            ans = Math.max(ans, arr[i]);
        }

        RollingHash h1 = new RollingHash(arr);
        RollingHash h2 = new RollingHash(revArr);
        for (int i = 1; i < n - 1; i++) {
            //for this centre;
            int mrodd = maxodd(i, h1, h2, n);
            if (mrodd != -1) {
                ans = Math.max(ans, pref[i + mrodd] - pref[i - mrodd + 1]);
            }
        }
        for (int i = 0; i < n-1; i++) {
            //for this centre;
            int mreven = maxeven(i, h1, h2, n);
            if (mreven != -1) {
                ans = Math.max(ans, pref[i + mreven + 1] - pref[i - mreven + 1]);
            }
        }
        return ans;

    }
}