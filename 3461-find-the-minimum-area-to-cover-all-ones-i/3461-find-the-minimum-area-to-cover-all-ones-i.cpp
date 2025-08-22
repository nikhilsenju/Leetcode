class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minrow,maxrow,mincol,maxcol;
        minrow = n;
        maxrow = 0;
        mincol = m;
        maxcol = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    minrow = min(minrow,i);
                    maxrow = max(maxrow,i);
                    mincol = min(mincol,j);
                    maxcol = max(maxcol,j);
                }    
            }
        }
        return (maxrow-minrow+1)*(maxcol-mincol+1);
    }
};