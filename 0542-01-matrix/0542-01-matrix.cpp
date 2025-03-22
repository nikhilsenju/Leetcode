class Solution {
public:
    struct P{
        int x;
        int y;
        int d;
        P(int x,int y, int d):x(x),y(y),d(d){}
    };
    void solve(vector<vector<int>>&mat,vector<vector<int>>&vis,vector<vector<int>>&dis){
        queue<P> q;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push(P(i,j,0));
                    vis[i][j]=1;
                }
            }
        }
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        while(!q.empty()){
            P cur = q.front();
            q.pop();
            dis[cur.x][cur.y]=cur.d;
            for(int i=0;i<4;i++){
                int nx = cur.x + dr[i];
                int ny = cur.y + dc[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                    q.push(P(nx,ny,cur.d+1));
                    vis[nx][ny]=1;
                }
            }
        }

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        solve(mat,vis,dis);
        return dis;
    }
};