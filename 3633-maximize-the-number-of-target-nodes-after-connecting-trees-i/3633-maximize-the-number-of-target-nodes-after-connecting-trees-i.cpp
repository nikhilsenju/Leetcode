class Solution {
public:
    int bfs(vector<vector<int>>&adj,int src,int k,int n){
        vector<int> vis(n,0);
        queue<int> q;
        q.push(src);
        int ans = 0;
        vis[src]=1;
        while(!q.empty() && k>=0){
            int sz = q.size();
            while(sz--){
                auto it = q.front();
                q.pop();
                ans++;
                for(auto i:adj[it]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }
            k--;
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);
        for(auto i:edges1){
            int u = i[0];
            int v = i[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto i:edges2){
            int u = i[0];
            int v = i[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int maxi = 0;
        vector<int> ans;
        for(int i=0;i<m;i++){
            int b = bfs(adj2,i,k-1,m);
            maxi = max(maxi,b);
        }
        maxi--;
        for(int i=0;i<n;i++){
            int b = bfs(adj1,i,k,n)+maxi+1;
            ans.push_back(b);
        }
        return ans;
        
       

    
    
    }
};