class Solution {
public:
    struct inf{
        int x,y,d;
        inf(int x,int y,int d):x(x),y(y),d(d){}
        struct compare{
            bool operator()(inf &a ,inf &b){
                return a.d>b.d;
            }
        };
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){return -1;}
        int n = grid.size();
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        priority_queue<inf,vector<inf>,inf :: compare>pq;
        pq.push(inf(0,0,1));
        dis[0][0]=1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x = it.x;
            int y = it.y;
            int d = it.d;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nx = x+i;
                    int ny = y+j;
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 &&(dis[x][y]+1<dis[nx][ny])){
                        dis[nx][ny]=1+dis[x][y];
                        pq.push(inf(nx,ny,dis[nx][ny]));
                    }
                }
            }
        }
        if(dis[n-1][n-1]==1e9){return -1;}
        return dis[n-1][n-1];
        
        
    }
};