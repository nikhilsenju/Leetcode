class Solution {
public:
  struct Pair{
        int x;
        int y;
        int time;
        Pair(int x,int y,int time):x(x),y(y),time(time){}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxTime = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<Pair> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(Pair(i,j,0));
                    vis[i][j]=1;
                }
            }
        }
        vector<int> row = {0,1,0,-1};
        vector<int> col = {1,0,-1,0};
        while(!q.empty()){
            Pair p = q.front();
            q.pop();
            int x = p.x;
            int y = p.y;
            int time = p.time;
            maxTime = max(maxTime,time);
            for(int i=0;i<4;i++){
                int nr = x+row[i];
                int nc = y+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && (!vis[nr][nc]) && grid[nr][nc]==1){
                    q.push(Pair(nr,nc,time+1));
                    vis[nr][nc]=1;
                    grid[nr][nc]=2;
                }
            }
            


        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return maxTime;
        
    }
};