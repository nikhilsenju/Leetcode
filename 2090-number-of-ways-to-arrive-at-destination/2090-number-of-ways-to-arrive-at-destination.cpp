class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
            
        }
        vector<long long> dist(n,LONG_MAX),ways(n,0);
        ways[0]=1;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        dist[0]=0;
        long long mod=(int)1e9+7;
        while(!pq.empty()){
            long long node,dis;
            dis=pq.top().first;
            node=pq.top().second;
            pq.pop();
            for(auto i:adj[node]){
                long long edw,adjnode;
                adjnode=i.first;
                edw=i.second;
                if(dis+edw<dist[adjnode]){
                    dist[adjnode]=dis+edw;
                    pq.push({dis+edw,adjnode});
                    ways[adjnode]=ways[node]%mod;
                }
                else if(dis+edw==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }

        }
        return ways[n-1]%mod;

        
    }
};