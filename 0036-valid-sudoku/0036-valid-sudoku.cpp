class Solution {
public:
    bool checkRowOrCol(vector<vector<char>>& mat, int idx, bool isRow) {
        vector<int> hash(10, 0);
        for (int i = 0; i < 9; i++) {
            char ch = isRow ? mat[idx][i] : mat[i][idx];
            if (ch >= '1' && ch <= '9') {
                int num = ch - '0';
                if (hash[num] > 0) return true; // duplicate found
                hash[num]++;
            }
        }
        return false;
    }

    bool checkSubgrid(vector<vector<char>>& mat, int r, int c) {
        vector<int> hash(10, 0);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                char ch = mat[i][j];
                if (ch >= '1' && ch <= '9') {
                    int num = ch - '0';
                    if (hash[num] > 0) return true; // duplicate found
                    hash[num]++;
                }
            }
        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        
        // check rows
        for (int i = 0; i < n; i++) {
            if (checkRowOrCol(board, i, true)) return false;
        }

        // check cols
        for (int i = 0; i < n; i++) {
            if (checkRowOrCol(board, i, false)) return false;
        }

        // check subgrids
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (checkSubgrid(board, 3 * i, 3 * j)) return false;
            }
        }
        return true;
    }
};
