class Solution {
public:
    struct inf {
        int val;
        int x;
        int y;
        inf(int val, int x, int y) : val(val), x(x), y(y) {}
        struct compare {
            bool operator()(inf& a, inf& b) { return a.val > b.val; }
        };
    };
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& v) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < v.size(); i++) {
            vp.push_back({v[i], i});
        }
        sort(vp.begin(), vp.end());
        vector<int> ans(v.size(), 0);
        priority_queue<inf, vector<inf>, inf::compare> pq;
        pq.push(inf(grid[0][0], 0, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;
        int sum = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        for (auto [value, idx] : vp) {
            while (!pq.empty() && pq.top().val < value) {
                auto it = pq.top();
                pq.pop();
                sum++;
                int val = it.val;
                int x = it.x;
                int y = it.y;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        !vis[nx][ny]) {
                        pq.push(inf(grid[nx][ny], nx, ny));
                        vis[nx][ny]=1;
                    }
                }
            }
            ans[idx] = sum;
        }

        return ans;
    }
};