class Solution {
public:
    vector<int> bfs(int src,vector<vector<int>>&adj){
        int n = adj.size();
        vector<int> dis(n,INT_MAX);
        vector<int> vis(n,0);
        dis[src]=0;
        vis[src]=1;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    dis[it]=1+dis[node];
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return dis;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]==-1){
                continue;
            }
            int u = i;
            int v = edges[i];
            adj[u].push_back(v);
        }

        int ans = -1;
        int maxi= INT_MAX;
        vector<int> dis1=bfs(node1,adj);
        vector<int> dis2=bfs(node2,adj);
        for(int i=0;i<n;i++){
            if(dis1[i]!=INT_MAX && dis2[i]!=INT_MAX){
                if(max(dis1[i],dis2[i])<maxi){
                    ans = i;
                    maxi = max(dis1[i],dis2[i]);
                }
            }
        }
        return ans;
    }
};