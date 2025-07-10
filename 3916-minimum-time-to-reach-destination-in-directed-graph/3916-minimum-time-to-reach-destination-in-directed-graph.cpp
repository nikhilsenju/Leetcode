#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 1e18;
struct st{
    ll u;
    ll s;
    ll e;
    
};
ll dijkstra(int n, int src, vector<vector<st>> &adj, vector<ll> &dist) {
    dist.assign(n, INF);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        ll node = it.second;
        ll time = it.first;
        if(time>dist[node]){
            continue;
        }
        for(auto i:adj[node]){
            ll ngh = i.u;
            ll si = i.s;
            ll ei = i.e;
            ll mini = INF;
            if(time>ei){
                continue;
            }
            if(time<si){
                ll cur = (si-time+1)+dist[node];
                mini = cur;
            }
            else if(time>=si && time<=ei){
                ll cur = 1+dist[node];
                mini = cur;
            }
            if(dist[ngh]>mini){
                dist[ngh]=mini;
                pq.push({dist[ngh],ngh});
            }
            
        }
    }
    if(dist[n-1]==INF){
        return -1;
    }
    return dist[n-1];
}

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<ll> dist;
        vector<vector<st>>adj(n);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int s = i[2];
            int e = i[3];
            adj[u].push_back({v,s,e});
        }
        return dijkstra(n,0,adj,dist);
    }
};