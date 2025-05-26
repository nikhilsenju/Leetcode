class Solution {
public:

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long  maxi = 0;
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        function<long long(int ,int)>dfs=[&](int r, int c){
            long long sum = 0;
            long long tmp = grid[r][c];
            grid[r][c]=0;
            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!=0){
                    sum=max(sum,dfs(nr,nc));
                }
            }
            grid[r][c]=tmp;
            return sum+tmp;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    maxi = max(maxi,dfs(i,j));
                }
            }
        }
        return maxi;
    }
};