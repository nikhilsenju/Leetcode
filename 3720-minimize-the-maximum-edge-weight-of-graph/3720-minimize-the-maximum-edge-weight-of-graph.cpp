class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int th) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto i : edges) {
            adj[i[1]].push_back({i[0], i[2]});
        }

        int lo = 1, hi = 1e6, ans = -1;

        auto chk = [&](int wt) {
            vector<int> vis(n + 1, 0);
            function<void(int)> dfs = [&](int node) {
                vis[node] = 1;
                for (auto i : adj[node]) {
                    if (i.second <= wt && !vis[i.first]) {
                        dfs(i.first);
                    }
                }
            };

            dfs(0); // Start DFS from node 1 (or any connected node)
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    return false;
                }
            }
            return true;
        };

        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (chk(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
