class Solution {
public:
    int LOG = 20;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> dist;

    void dfs(int node, int par, vector<pair<int, int>> adj[]) {
        for (auto [nbr, wt] : adj[node]) {
            if (nbr != par) {
                dist[nbr] = dist[node] + wt;
                dfs(nbr, node, adj);
            }
        }
    }

    void preprocess(int root, int n, vector<pair<int, int>> adj[]) {
        up.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);

        function<void(int, int)> dfs2 = [&](int node, int par) {
            up[node][0] = par;
            for (int i = 1; i < LOG; ++i) {
                if (up[node][i - 1] != -1)
                    up[node][i] = up[up[node][i - 1]][i - 1];
            }
            for (auto [nbr, _] : adj[node]) {
                if (nbr != par) {
                    depth[nbr] = depth[node] + 1;
                    dfs2(nbr, node);
                }
            }
        };

        dfs2(root, -1);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != -1 && depth[up[u][i]] >= depth[v])
                u = up[u][i];
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int getDist(int u, int v) {
        return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }

    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<pair<int, int>> adj[n];
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        dist.assign(n, 0);
        dfs(0, -1, adj);
        preprocess(0, n, adj);

        vector<int> ans;
        for (auto& q : queries) {
            int a = q[0], b = q[1], c = q[2];
            int dab = getDist(a, b);
            int dac = getDist(a, c);
            int dbc = getDist(b, c);
            ans.push_back((dab + dac + dbc) / 2);
        }
        return ans;
    }
};
