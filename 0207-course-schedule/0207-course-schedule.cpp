class Solution {
public:

    bool dfs(int node , vector<int>&vis,vector<int>&curvis,vector<vector<int>>&adj){
        vis[node]=1;
        curvis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i,vis,curvis,adj)){
                    return true;
                }
            }
            else{
                if(curvis[i]){
                    return true;
                }
            }
        }
        curvis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& v) {
        vector<vector<int>> adj(n);
        for(auto i:v){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>curvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,curvis,adj)){
                    return false;
                }
            }
        }
        return true;

        
    }
};