class Solution {
public:
    struct inf {
        int stop;
        int node;
        inf(int stop, int node) : stop(stop), node(node) {}
    };
    
    int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto i : v) {
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        vector<vector<int>> dis(n, vector<int>(k + 2, 1e9));
        queue<inf> q;
        q.push(inf(0, src));
        dis[src][0] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.stop;
            int node = it.node;

            if (stops > k) continue;

            for (auto i : adj[node]) {
                int ngh = i.first;
                int wt = i.second;
                if (dis[ngh][stops + 1] > dis[node][stops] + wt) {
                    dis[ngh][stops + 1] = dis[node][stops] + wt;
                    q.push(inf(stops + 1, ngh));
                }
            }
        }
        
        int mini = *min_element(dis[dst].begin(), dis[dst].end());
        return mini == 1e9 ? -1 : mini;
    }
};
