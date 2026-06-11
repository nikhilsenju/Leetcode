const int MOD = 1e9+7;
class Solution {
public:
    long long binpower(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+2];
        vector<int> vis(n+2);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int,int>> q;
        q.push({1,0});
        vis[1]=1;
        int maxDepth = 0;
        while(!q.empty()){
            auto [node,curDepth] = q.front();
            q.pop();
            maxDepth = max(maxDepth,curDepth);
            for(auto ngh:adj[node]){
                if(!vis[ngh]){
                    q.push({ngh,curDepth+1});
                    vis[ngh]=1;

                }
            }
        }
        int ans = binpower(2,maxDepth-1);
        return ans;
        
        
    }
};