class Solution {
public:
    struct Node {
        int x;
        int y;
        int val;
        Node(int x, int y, int val) : x(x), y(y), val(val) {}
        bool operator>(const Node& other) const { return val > other.val; }
    };

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        int ans = 0;
        vector<pair<int, int>> vp;
        for (int i = 0; i < q.size(); i++) {
            vp.push_back({q[i], i});
        }
        sort(vp.begin(), vp.end());

        vector<int> res(q.size(), 0);
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        pq.push(Node(0, 0, grid[0][0]));
        vis[0][0] = 1;
        for (auto it : vp) {
            int val = it.first;
            int idx = it.second;
            while (!pq.empty() && pq.top().val < val) {
                auto it = pq.top();
                pq.pop();
                ans++;
                int val = it.val;
                int x = it.x;
                int y = it.y;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        !vis[nx][ny]) {
                        pq.push(Node(nx, ny,grid[nx][ny]));
                        vis[nx][ny] = 1;
                    }
                }
            }
            res[idx] = ans;
        }
        return res;
    }
};
