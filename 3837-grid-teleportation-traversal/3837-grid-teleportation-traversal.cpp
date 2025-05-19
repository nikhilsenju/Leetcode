class Solution {
public:
    struct Node {
        int x;
        int y;
        int curdis;
        Node(int x,int y,int curdis):x(x),y(y),curdis(curdis){};
        bool operator>(const Node& other) const {
            return curdis > other.curdis;
        }
    };

    int minMoves(vector<string>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<char, vector<pair<int, int>>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] >= 'A' && mat[i][j] <= 'Z') {
                    mp[mat[i][j]].push_back({i, j});
                }
            }
        }

        unordered_set<char> used;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int i = it.x;
            int j = it.y;
            int curdis = it.curdis;

            if (curdis != dist[i][j]) continue;

            if (i == n - 1 && j == m - 1) {
                return curdis;
            }

            if (mat[i][j] >= 'A' && mat[i][j] <= 'Z' && used.find(mat[i][j]) == used.end()) {
                used.insert(mat[i][j]);
                for (auto& k : mp[mat[i][j]]) {
                    if (curdis < dist[k.first][k.second]) {
                        dist[k.first][k.second] = curdis;
                        pq.push({k.first, k.second, curdis});
                    }
                }
            }

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj]!='#' && curdis + 1 < dist[ni][nj]) {
                    dist[ni][nj] = curdis + 1;
                    pq.push({ni, nj, dist[ni][nj]});
                }
            }
        }

        return -1;
    }
};
