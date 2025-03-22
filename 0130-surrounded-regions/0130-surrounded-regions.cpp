class Solution {
public:
    vector<int> dr ={-1,0,1,0};
    vector<int> dc ={0,1,0,-1};
    void dfs(int i ,int j , vector<vector<int>>&vis,vector<vector<char>>&v){
        vis[i][j]=1;
        for(int k = 0;k<4;k++){
            int  nr = i+dr[k];
            int  nc = j+dc[k];
            if(nr>=0 && nr<v.size() && nc>=0 && nc<v[0].size() && !vis[nr][nc] && v[nr][nc]=='O'){
                dfs(nr,nc,vis,v);
            }
        }

    }
    void solve(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='O' && (i==0 || i==n-1 || j==0 ||j==m-1)){
                    dfs(i,j,vis,v);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]==1 && v[i][j]=='O'){
                    v[i][j]='X';

                }
            }
        }  
    }
};