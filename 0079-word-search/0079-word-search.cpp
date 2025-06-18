class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    bool dfs(int r, int c, vector<vector<char>>& board, string& word, int idx) {
        if (r < 0 || r >=board.size() || c < 0 || c >=board[0].size() || 
            board[r][c] != word[idx]) {
            return false;
        }
        if (idx == word.size()-1 && word[idx]==board[r][c]) {
            return true;
        }
        char tmp = board[r][c];
        board[r][c] = '.';
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (dfs(nr, nc, board, word, idx + 1)) {
                return true;
            }
        }
        board[r][c] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};