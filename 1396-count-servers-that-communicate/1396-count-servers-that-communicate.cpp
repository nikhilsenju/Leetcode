class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n+1,0);
        vector<int> col(m+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row[i]--;
                    col[j]--;

                    if(row[i]!=0 || col[j]!=0){
                        ans++;
                    }
                    row[i]++;
                    col[j]++;
                }
            }
        }
        return ans;
        
    }
};