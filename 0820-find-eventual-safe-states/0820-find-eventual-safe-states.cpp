class Solution {
public:
    vector<int> kahn(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto j : adj[i]) {
                ind[j]++;
            }
        }
        queue<int> q;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            ans.push_back(it);
            for (auto j : adj[it]) {
                ind[j]--;
                if(ind[j]==0 && !vis[j]){
                        q.push(j);
                        vis[j] = 1;
                    }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (auto j : graph[i]) {
                adj[j].push_back(i);
            }
        }
        return kahn(adj);
    }
};