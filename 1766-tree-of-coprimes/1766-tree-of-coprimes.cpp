class Solution {
public:
    vector<int> depth;
    unordered_map<int, int> mp;
    vector<int> ans;
    vector<int> vis;

    void dfs(int node, vector<int> adj[], vector<int>& nums) {
        vis[node] = 1;

        int val = nums[node];
        int dep = depth[node];

        int maxi = -1;
        int find = -1;

        for (auto i : mp) {
            int curr = i.first;
            int cind = i.second;

            if (__gcd(curr, val) == 1 && maxi < depth[cind]) {
                maxi = depth[cind];
                find = cind;
            }
        }

        if (maxi == -1)
            ans[node] = -1;
        else
            ans[node] = find;

        int old = -1;

        if (mp.count(val)) {
            old = mp[val];
            // keeping your logic as close as possible
            if(dep>depth[mp[val]]){
                mp[val]=node;
            }
        } else {
            mp[val] = node;
        }

        for (auto ngh : adj[node]) {
            if (!vis[ngh]) {
                dfs(ngh, adj, nums); // Fixed
            }
        }

        if (old == -1)
            mp.erase(val);
        else
            mp[val] = old;
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        vector<int> adj[n];

        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.assign(n, 0);
        ans.assign(n, -1);
        vis.assign(n, 0);

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 1;

        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();

            depth[node] = d;

            for (auto ngh : adj[node]) {
                if (!vis[ngh]) {
                    q.push({ngh, d + 1});
                    vis[ngh] = 1;
                }
            }
        }
        vis.assign(n, 0);
        dfs(0, adj, nums); // Fixed

        return ans;
    }
};