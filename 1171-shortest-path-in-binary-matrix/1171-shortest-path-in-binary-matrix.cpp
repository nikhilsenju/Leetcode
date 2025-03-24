class Solution {
public:
    struct inf{
        int x,y,d;
        inf(int x,int y,int d):x(x),y(y),d(d){}
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return -1;
        }
        int n =grid.size();
        queue<inf> q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push(inf(0,0,1));
        vis[0][0]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.x;
            int y = it.y;
            int d = it.d;
            if(x==n-1 && y==n-1){
                return d;
            }
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nx = x+i;
                    int ny = y+j;
                    if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny] && grid[nx][ny]==0){
                        q.push(inf(nx,ny,d+1));
                        vis[nx][ny]=1;
                    }

                }
            }
        }
        return -1;
        
    }
};