class Solution {
public:
    void dfs(int node , vector<int>&vis,vector<vector<int>>&adj){
        if(vis[node]){
            return;
        }
        vis[node]=1;
        for(auto i:adj[node]){
            dfs(i,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int count =0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;

        
    }
};