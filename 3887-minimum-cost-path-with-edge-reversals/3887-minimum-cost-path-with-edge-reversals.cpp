class Solution {
public:
    int minCost(vector<vector<pair<int,int>>>&adj){
        int n = adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int curnode = it.second;
            int curdis = it.first;
            if(curdis!=dis[curnode]){
                continue;
            }
            for(auto i:adj[curnode]){
                int ngh = i.first;
                int adjdis = i.second;
                if(dis[curnode]+adjdis<dis[ngh]){
                    dis[ngh]=dis[curnode]+adjdis;
                    pq.push({dis[ngh],ngh});
                }
            }
        }
        return dis[n-1]==INT_MAX?-1:dis[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }
        return minCost(adj);


    }
};