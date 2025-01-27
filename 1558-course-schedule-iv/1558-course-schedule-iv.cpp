class Solution {
public:
    void dfs(int con,int node  ,map<int,set<int>>&mp, vector<int>&vis,vector<int>adj[]){
        if(vis[node]==1){return;}
        vis[node]=1;
        mp[con].insert(node);
        for(auto i:adj[node]){
            if(vis[i]==0){
                dfs(con,i,mp,vis,adj);
            }
        }
        return;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& v, vector<vector<int>>&  q) {
        vector<int> adj[105];
        for(auto i:v){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        map<int,set<int>>mp;
        for(int i=0;i<n;i++){
            vector<int> vis(n+1,0);
            dfs(i,i,mp,vis,adj);
        }
        vector<bool> ans;
        for(auto i:q){
            int u = i[0];
            int v = i[1];
            if(mp[u].count(v)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
       
       
        


        
    }
};