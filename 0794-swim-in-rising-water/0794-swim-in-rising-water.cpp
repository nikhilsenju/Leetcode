class Solution {
public:
    struct inf{
        int wt;
        int x;
        int y;
        inf(int wt,int x,int y):x(x),y(y),wt(wt){}
        struct compare{
            bool operator()(inf &a ,inf &b){
                return a.wt>b.wt;
            }
        };
    };
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // int n = grid[0].size();
        priority_queue<inf,vector<inf>,inf::compare>pq;
        pq.push(inf(grid[0][0],0,0));
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        dis[0][0]=grid[0][0];
        vector<int> dx={-1,0,1,0};
        vector<int> dy ={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.wt;
            int x = it.x;
            int y = it.y;
            if(dis[x][y]!=wt){
                continue;
            }
            for(int k=0;k<4;k++){
                int nr = x+dx[k];
                int nc = y+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int maxi = max(wt,grid[nr][nc]);
                    if(dis[nr][nc]>maxi){
                        dis[nr][nc]=maxi;
                        pq.push(inf(maxi,nr,nc));
                    }
                }
            }
        }
        return dis[n-1][n-1]; 
    }
};