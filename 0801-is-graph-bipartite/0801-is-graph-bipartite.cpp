class Solution {
public:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph, vector<int>& vis) {
        color[node] = col;
        vis[node] = 1;
        for (auto i : graph[node]) {
            if (!vis[i]) {
                if (dfs(i, !col, color, graph, vis)) {
                    return true;
                }
            } else {
                if (color[i] == color[node]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, 0, color, graph, vis)) {
                    return false;
                }
            }
        }
        return true;
    }
};
