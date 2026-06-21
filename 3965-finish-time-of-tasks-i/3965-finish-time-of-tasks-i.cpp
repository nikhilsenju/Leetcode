class Solution {
public:
    long long dfs(int u,vector<vector<int>>&adj,vector<int>&bt,vector<int>&vis){
        vis[u]=1;
        if(u!=0 && adj[u].size()==1){
            return bt[u];
        }
        long long maxi = -1e18;
        long long mini = 1e18;
        for(auto ngh:adj[u]){
            if(vis[ngh]){
                continue;
            }
            long long ct = dfs(ngh,adj,bt,vis);;
            maxi = max(maxi,ct);
            mini = min(mini,ct);
        }
        long long ans = maxi-mini+bt[u];
        ans+=maxi;
        return ans;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& bt) {
        if(n==1){
            return bt[0];
        }
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0,adj,bt,vis);
        

    }
};