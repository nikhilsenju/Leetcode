class Solution {
public:
    int dfs(vector<int> adj[], int node, int par, int cur, vector<int>& col) {
        col[node] = cur;
        int res = cur;
        for (auto i : adj[node]) {
            if (i != par) {
                res += dfs(adj, i, node, !cur, col);
            }
        }
        return res;
    }
    vector<int> build(vector<vector<int>>& edge,vector<int>&col) {
        int n = edge.size() + 1;
        vector<int> adj[n];
        for (auto i : edge) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = dfs(adj,0,-1,0,col);
        return { n - res,res};
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> col1(n, 0);
        vector<int> col2(m, 0);
        vector<int> count1 = build(edges1,col1);
        vector<int> count2 = build(edges2,col2);
        vector<int> ans;
        for(int i=0;i<n;i++){
            int cur = count1[col1[i]]+max(count2[0],count2[1]);
            ans.push_back(cur);
        }
        return ans;
    }
};