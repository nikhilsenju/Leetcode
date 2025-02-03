class Solution {
public:
    bool f(int i, int j, vector<vector<char>>& board, string& word, int ind) {
        if (ind == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[ind]) {
            return false;
        }

        char c = board[i][j];
        board[i][j] = 'V';
        bool ans = (f(i + 1, j, board, word, ind + 1) ||
                    f(i - 1, j, board, word, ind + 1) ||
                    f(i, j + 1, board, word, ind + 1) ||
                    f(i, j - 1, board, word, ind + 1));
        board[i][j] = c;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (f(i, j, board, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};