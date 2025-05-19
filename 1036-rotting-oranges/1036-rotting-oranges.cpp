class Solution {
public:
    struct Node {
        int x;
        int y;
        int time;
        Node(int x, int y, int time) : x(x), y(y), time(time) {};
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<Node> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push(Node(i, j, 0));
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }
        int minTime = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.x;
            int y = it.y;
            int time = it.time;
            minTime = max(minTime, time);
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
                    grid[nx][ny] == 1 && 1 + time < dist[nx][ny]) {
                    grid[nx][ny] = 2;
                    q.push(Node(nx, ny, time + 1));
                    vis[nx][ny] = 1;
                    dist[nx][ny] = time + 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minTime;
    }
};