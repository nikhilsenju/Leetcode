class Cell {
public:
    int height, r, c;
    Cell(int height, int r, int c) : height(height), r(r), c(c) {}
    bool operator<(const Cell& other) const { 
        return height > other.height;  // Min-heap behavior
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& vp) {
        int n = vp.size();
        int m = vp[0].size();
        priority_queue<Cell> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Push border cells into the priority queue and mark as visited
        for (int i = 0; i < n; i++) {
            pq.push(Cell(vp[i][0], i, 0));
            pq.push(Cell(vp[i][m-1], i, m-1));
            vis[i][0] = 1;
            vis[i][m-1] = 1;
        }
        for (int j = 0; j < m; j++) {
            pq.push(Cell(vp[0][j], 0, j));
            pq.push(Cell(vp[n-1][j], n-1, j));
            vis[0][j] = 1;
            vis[n-1][j] = 1;
        }

        long long ans = 0;
        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {1, 0, -1, 0};
        
        while (!pq.empty()) {
            Cell current = pq.top();
            pq.pop();
            int h = current.height, r = current.r, c = current.c;
            
            for (int k = 0; k < 4; k++) {
                int nr = r + row[k];
                int nc = c + col[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    ans += max(0, h - vp[nr][nc]);
                    pq.push(Cell(max(h, vp[nr][nc]), nr, nc));
                    vis[nr][nc] = 1;  // Mark as visited
                }
            }
        }
        return ans;
    }
};
