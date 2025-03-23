class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<vector<int>>adj(n);
        vector<int> ind(n,0);
        for(auto i:v){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
            ind[u]++;

        }
        queue<int> q;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto i:adj[x]){
                if(!vis[i]){
                    ind[i]--;
                    if(ind[i]==0){
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }
        }
        if(ans.size()!=n){
            return {};
        }
        return ans;


        
    }
};