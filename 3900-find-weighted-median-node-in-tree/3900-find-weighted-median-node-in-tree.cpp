class BL {
private:
    long long  n;
    long long  LOG;
    vector<vector<long long >> dp;
    vector<long long > depth;
    vector<long long > dist; // Store distance from root
    vector<vector<pair<long long , long long >>> adj; // (neighbor, weight)

    void dfs(long long  u, long long  parent, long long  w) {
        depth[u] = (parent == -1 ? 0 : depth[parent] + 1);
        dist[u] = (parent == -1 ? 0 : dist[parent] + w);
        dp[u][0] = parent;

        for (long long  i = 1; i < LOG; i++) {
            if (dp[u][i - 1] == -1) {
                dp[u][i] = -1;
            } else {
                dp[u][i] = dp[dp[u][i - 1]][i - 1];
            }
        }

        for (auto [v, weight] : adj[u]) {
            if (v == parent) continue;
            dfs(v, u, weight);
        }
    }

public:
    BL(long long  n, vector<vector<pair<long long , long long >>> adj, long long  root = 0) : n(n), adj(adj) {
        depth.assign(n, 0);
        dist.assign(n, 0);
        LOG = 0;
        while((1 << LOG) <= n) LOG++;
        dp.assign(n, vector<long long >(LOG, -1));

        dfs(root, -1, 0);
    }

    long long  find_kth_parent(long long  u, long long  k) {
        for (long long  i = 0; i < LOG; i++) {
            if (u == -1) break;
            if (k & (1 << i)) {
                u = dp[u][i];
            }
        }
        return u;
    }

    long long  lca(long long  u, long long  v) {
        if (depth[u] < depth[v]) swap(u, v);
        long long  diff = depth[u] - depth[v];
        for (long long  i = 0; i < LOG; i++) {
            if (diff & (1 << i)) {
                u = dp[u][i];
            }
        }
        if (u == v) return u;

        for (long long  i = LOG - 1; i >= 0; i--) {
            if (dp[u][i] != dp[v][i]) {
                u = dp[u][i];
                v = dp[v][i];
            }
        }
        return dp[u][0];
    }

    long long  distance(long long  u, long long  v) {
        long long  L = lca(u, v);
        return dist[u] + dist[v] - 2 * dist[L];
    }

    long long  getDepth(long long  u) {
        return depth[u];
    }
};

class Solution {
private:
    BL *bs;

    long long  check_left(long long  u, long long  lca, long long  tot) {
        long long  ans = -1;
        long long  lo = 0;
        long long  hi = bs->getDepth(u) - bs->getDepth(lca);
        while (hi >= lo) {
            long long  mid = (hi + lo) >> 1;
            long long  node = bs->find_kth_parent(u, mid);
            long long  dis = bs->distance(u, node);
            if (2 * dis >= tot) {
                ans = node;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    long long  check_right(long long  v, long long  lca, long long  tot) {
        long long  ans = -1;
        long long  lo = 0;
        long long  hi = bs->getDepth(v) - bs->getDepth(lca);
        while (hi >= lo) {
            long long  mid = (hi + lo) >> 1;
            long long  node = bs->find_kth_parent(v, mid);
            long long  dis = bs->distance(v, node);
            if (2 * dis <= tot) {
                ans = node;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> findMedian(int  n, vector<vector<int >> &edges, vector<vector<int >> &queries) {
        vector<vector<pair<long long , long long >>> adj(n);
        for (auto &i : edges) {
            long long  u = i[0];
            long long  v = i[1];
            long long  wt = i[2];
            adj[u].push_back({v, wt}); 
            adj[v].push_back({u, wt}); 
        }

        BL bl(n, adj);
        bs = &bl;

        vector<int > ans(queries.size(), -1);
        for (long long  i = 0; i < (long long )queries.size(); i++) {
            long long  u = queries[i][0];
            long long  v = queries[i][1];
            long long  lca = bl.lca(u, v);
            long long  tot = bl.distance(u, v);
            long long  left = check_left(u, lca, tot);
            if (left == -1) {
                ans[i] = check_right(v, lca, tot);
            } else {
                ans[i] = left;
            }
        }
        return ans;
    }
};

