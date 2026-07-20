class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        List<List<Integer>> v = new ArrayList();
        int[][] ans = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[(i+(j+k)/n)%m][(j+k)%n]=grid[i][j];
            }
        }
        for(int i=0;i<m;i++){
            List<Integer> tmp = new ArrayList();
            for(int j=0;j<n;j++){
                tmp.add(ans[i][j]);
            }
            v.add(tmp);
        }
        return v;
    }
}