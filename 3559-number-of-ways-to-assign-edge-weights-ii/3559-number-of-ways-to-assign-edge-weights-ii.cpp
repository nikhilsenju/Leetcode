class LCA {
    int n, maxLog;
    vector<vector<int>> up;
    vector<int> depth;

public:
    LCA(int n, const vector<vector<int>>& adj, int root = 1) : n(n) {
        maxLog = 32 - __builtin_clz(n);
        up.assign(n + 1, vector<int>(maxLog));
        depth.assign(n + 1, 0);
        dfs(root, root, adj);
    }

    void dfs(int node, int parent, const vector<vector<int>>& adj) {
        up[node][0] = parent;
        for (int i = 1; i < maxLog; ++i)
            up[node][i] = up[up[node][i - 1]][i - 1];

        for (int child : adj[node]) {
            if (child != parent) {
                depth[child] = depth[node] + 1;
                dfs(child, node, adj);
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        // Bring u and v to same depth
        for (int i = maxLog - 1; i >= 0; --i)
            if (depth[u] - (1 << i) >= depth[v])
                u = up[u][i];

        if (u == v)
            return u;

        // Lift both u and v until they meet
        for (int i = maxLog - 1; i >= 0; --i)
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }

        return up[u][0];
    }
    int getdepth(int node){
        return depth[node];
    }
};


class Solution {
public:
    const int MOD = 1e9+7;
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
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        LCA lca(n,adj);
        vector<int> ans;
        for(auto i:queries){
            int u = i[0];
            int v = i[1];
            if(u==v){
                ans.push_back(0);
                continue;
            }
            int lcp = lca.getLCA(u,v);
            int len = lca.getdepth(u)+lca.getdepth(v)-2*lca.getdepth(lcp);
            int dis = binpower(2,len-1);
            ans.push_back(dis);
        }
        return ans;
    }
};