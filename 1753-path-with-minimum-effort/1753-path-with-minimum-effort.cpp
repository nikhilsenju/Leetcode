class Solution {
public:
    struct inf{
        int x,y,d;
        inf(int x,int y,int d):x(x),y(y),d(d){}
        struct compare{
            bool operator()(inf &a,inf &b){
                return a.d>b.d;
            }
        };
    };
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        priority_queue<inf,vector<inf>,inf::compare> pq;
        pq.push(inf(0,0,0));
        dis[0][0]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x = it.x;
            int y = it.y;
            int d = it.d;
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int curmaxi = max(dis[x][y],abs(v[nx][ny]-v[x][y]));
                    if(curmaxi<dis[nx][ny]){
                        dis[nx][ny]=curmaxi;
                        pq.push(inf(nx,ny,dis[nx][ny]));
                    }
                }
            }

        }
        return dis[n-1][m-1];
        
    }
};