class Solution {
public:
    int networkDelayTime(vector<vector<int>>& v, int n, int k) {
        //build graph
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:v){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v,wt});
        }
        //dikstra 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> dis(n+5,1e9);
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int curdis = it.first;
            if(dis[node]!=curdis){
                continue;
            }
            for(auto i:adj[node]){
                int ngh = i.first;
                int wt = i.second;
                if(dis[ngh]>dis[node]+wt){
                    dis[ngh]=dis[node]+wt;
                    pq.push({dis[ngh],ngh});
                }
            }

        }
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9){
                return -1;
            }
            maxi = max(maxi,dis[i]);
        }
        return maxi;


        
    }
};