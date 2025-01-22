class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {1, 0, -1, 0};
        queue<tuple<int, int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 1) {
                    q.push({0,i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int maxi=0;
        while(!q.empty()){
            auto [h,r,c]=q.front();
            ans[r][c]=h;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc=c+col[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                    q.push({h+1,nr,nc});
                    vis[nr][nc]=1;
                }
            }
            
        }
        return ans;
    }
};