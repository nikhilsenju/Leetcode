import java.util.*;

class Solution {

    class Fenwick {
        long[] bit;

        Fenwick(int n) {
            bit = new long[n + 2];
        }

        void update(int idx, long val) {
            while (idx < bit.length) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        long query(int idx) {
            long sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    }

    public long countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;

        // Convert to +1 / -1
        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] == target) ? 1 : -1;
        }

        // Prefix sum
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        Fenwick ft = new Fenwick(2 * n + 5);

        long ans = 0;
        int offset = n + 2;

        for (int pref : nums) {

            if (pref > 0)
                ans++;

            ans += ft.query(pref - 1 + offset);

            ft.update(pref + offset, 1);
        }

        return ans;
    }
}