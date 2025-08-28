class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            int curr = i;
            int curc = 0;
            while (curr < n && curc < n) {
                tmp.push_back(grid[curr][curc]);
                curr++;
                curc++;
            }
            sort(tmp.rbegin(), tmp.rend());
            curr = i;
            curc = 0;
            int j = 0;
            while (curr < n && curc < n) {
                grid[curr][curc] = tmp[j];
                curr++;
                curc++;
                j++;
            }
        }
        for (int j = 1; j < n; j++) {
            vector<int> tmp;
            int curr = 0;
            int curc = j;
            while (curr < n && curc < n) {
                tmp.push_back(grid[curr][curc]);
                curr++;
                curc++;
            }
            sort(tmp.begin(), tmp.end());
            curr = 0;
            curc = j;
            int i = 0;
            while (curr < n && curc < n) {
                grid[curr][curc] = tmp[i];
                curr++;
                curc++;
                i++;
            }
        }
        return grid;
    }
};