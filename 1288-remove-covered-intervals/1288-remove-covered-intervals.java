import java.util.*;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] row1, int[] row2) {
                if(row1[0]!=row2[0]){
                    return Integer.compare(row1[0],row2[0]);
                }
                return -Integer.compare(row1[1],row2[1]);
            }
        });
        int s = intervals[0][0];
        int e = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            if (s <= cs && ce <= e) {
                continue;
            } else {
                ans++;
                s = cs;
                e = ce;
            }
        }
        return ans;
    }
}