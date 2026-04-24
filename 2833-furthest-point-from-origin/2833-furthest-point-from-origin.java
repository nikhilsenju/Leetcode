class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int l = 0;
        int r = 0;
        int b = 0;
        int n = moves.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (moves.charAt(i) == 'L') {
                l++;
            } 
            else if (moves.charAt(i) == 'R') {
                r++;
            }
        }

        b = n - l - r;   // blanks '_'
        ans = b + Math.abs(l - r);

        return ans;
    }
}