class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // Multi-source BFS to calculate minimum distance from any thief
    vector<vector<int>> getSafenessMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }

        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int> cell = q.front();
                q.pop();
                int x = cell.first;
                int y = cell.second;
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dirs[k][0];
                    int ny = y + dirs[k][1];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        dist[nx][ny] = level + 1;
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }

        return dist;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> safeness = getSafenessMatrix(grid);

        vector<vector<int>> maxMin(n, vector<int>(m, -1));
        // Max-heap priority queue: (safeness, x, y)
        priority_queue<vector<int>> pq;
        pq.push({safeness[0][0], 0, 0});
        maxMin[0][0] = safeness[0][0];

        while (!pq.empty()) {
            vector<int> top = pq.top(); pq.pop();
            int safe = top[0], x = top[1], y = top[2];
            if (x == n - 1 && y == m - 1) return safe;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newSafe = min(safe, safeness[nx][ny]);
                    if (newSafe > maxMin[nx][ny]) {
                        maxMin[nx][ny] = newSafe;
                        pq.push({newSafe, nx, ny});
                    }
                }
            }
        }

        return 0; // No path found
    }
};
