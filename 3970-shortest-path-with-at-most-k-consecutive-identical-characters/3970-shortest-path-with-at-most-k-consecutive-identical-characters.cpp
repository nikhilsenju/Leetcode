class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<long long,long long>>adj[n]; 
        for(auto i:edges){
            long long u = i[0];
            long long v = i[1];
            long long w = i[2];
            adj[u].push_back({v,w});
        }
        vector<vector<long long>> dist(n,vector<long long>(k+2,LLONG_MAX));
        priority_queue<tuple<long long,long long,long long>,vector<tuple<long long,long long,long long>>,greater<tuple<long long,long long,long long>>> pq;
        dist[0][1]=0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto [curd,curn,curk] = pq.top();
            pq.pop();
            if(dist[curn][curk]<curd){
                continue;
            }
            for(auto i:adj[curn]){
                long long ngh = i.first;
                long long wt = i.second;
                long long nextk = curk;
                if(labels[curn]==labels[ngh]){
                    nextk+=1;
                }
                else{
                    nextk = 1;
                }
                if(curd+wt<dist[ngh][nextk] && nextk<=k){
                    dist[ngh][nextk]=wt+curd;
                    pq.push({dist[ngh][nextk],ngh,nextk});
                }

            }
        }
        long long ans = LLONG_MAX;
        for(int i=1;i<=k;i++){
            ans = min(ans,dist[n-1][i]);
        }
        return ans==LLONG_MAX?-1:ans;
        
    }
};