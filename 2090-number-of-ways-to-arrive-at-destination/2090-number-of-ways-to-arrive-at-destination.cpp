class Solution {
public:
    long long mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& v) {
      
        //buid graph
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto i:v){
            long long u = i[0];
            long long v = i[1];
            long long wt = i[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        //algorithm 
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        vector<long long> dis(n,1e18);
        dis[0]=0;
        vector<long long>count(n,0);
        count[0]=1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long curdis = it.first;
            long long node = it.second;
            if(curdis!=dis[node]){
                continue;
            }
            for(auto i:adj[node]){
                long long ngh = i.first;
                long long wt = i.second;
                if(dis[ngh]>dis[node]+wt){
                    dis[ngh]=dis[node]+wt;
                    pq.push({dis[ngh],ngh});
                    count[ngh]=(count[node])%mod;
                }
                else if(dis[ngh]==dis[node]+wt){
                    count[ngh]=(count[node]+count[ngh])%mod;
                }
            }
        }
        return count[n-1]%mod;


        
    }
};