class BL {
private:
    long long n;
    long long LOG;
    vector<vector<long long>> dp;
    vector<long long> depth;
    vector<long long> dist;                         // Store distance from root
    vector<vector<pair<long long, long long>>> adj; // (neighbor, weight)

    void dfs(long long u, long long parent, long long w) {
        depth[u] = (parent == -1 ? 0 : depth[parent] + 1);
        dist[u] = (parent == -1 ? 0 : dist[parent] + w);
        dp[u][0] = parent;

        for (long long i = 1; i < LOG; i++) {
            if (dp[u][i - 1] == -1) {
                dp[u][i] = -1;
            } else {
                dp[u][i] = dp[dp[u][i - 1]][i - 1];
            }
        }

        for (auto [v, weight] : adj[u]) {
            if (v == parent)
                continue;
            dfs(v, u, weight);
        }
    }

public:
    BL(long long n, vector<vector<pair<long long, long long>>> adj,
       long long root = 0)
        : n(n), adj(adj) {
        depth.assign(n, 0);
        dist.assign(n, 0);
        LOG = 0;
        while ((1 << LOG) <= n)
            LOG++;
        dp.assign(n, vector<long long>(LOG, -1));

        dfs(root, -1, 0);
    }

    long long find_kth_parent(long long u, long long k) {
        for (long long i = 0; i < LOG; i++) {
            if (u == -1)
                break;
            if (k & (1 << i)) {
                u = dp[u][i];
            }
        }
        return u;
    }

    long long lca(long long u, long long v) {
        if (depth[u] < depth[v])
            swap(u, v);
        long long diff = depth[u] - depth[v];
        for (long long i = 0; i < LOG; i++) {
            if (diff & (1 << i)) {
                u = dp[u][i];
            }
        }
        if (u == v)
            return u;

        for (long long i = LOG - 1; i >= 0; i--) {
            if (dp[u][i] != dp[v][i]) {
                u = dp[u][i];
                v = dp[v][i];
            }
        }
        return dp[u][0];
    }

    long long distance(long long u, long long v) {
        long long L = lca(u, v);
        return dist[u] + dist[v] - 2 * dist[L];
    }

    long long getDepth(long long u) { return depth[u]; }
};

class Solution {
public:
    BL* bl;
    vector<int> countSubgraphsForEachDiameter(int n,
                                              vector<vector<int>>& edges) {
        // first all possible combinations
        for (auto& i : edges) {
            i[0]--;
            i[1]--;
        }
        vector<vector<pair<long long, long long>>> adj(n);
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
        bl = new BL(n, adj);
        set<pair<int, int>> st;
        for (auto i : edges) {
            st.insert({i[0], i[1]});
        }
        vector<vector<int>> ans;
        for (int i = 1; i < (1 << n); i++) {
            int num = i;
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & num) {
                    tmp.push_back(j);
                }
            }
            if (tmp.size() < 2) {
                continue;
            }
            ans.push_back(tmp);
        }
        vector<int> res(n - 1, 0);
        for (auto v : ans) {
            int c = 0;
            int maxi = 0;
            for (int i = 0; i < v.size(); i++) {
                for (int j = i + 1; j < v.size(); j++) {
                    if (st.count({v[i], v[j]})) {
                        c++;
                    }
                    int u = v[i];
                    int vv = v[j];
                    int dis = bl->distance(u, vv);
                    maxi = max(maxi, dis);
                }
            }
            if (c == v.size() - 1) { // valid
                for (auto i : v) {
                    cout << i << " ";
                }
                cout << "-";
                cout << maxi << endl;
                res[maxi - 1]++;
            }
        }
        return res;
    }
};