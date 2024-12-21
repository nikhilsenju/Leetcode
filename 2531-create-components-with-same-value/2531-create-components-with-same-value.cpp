class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int st = 0, last = 0;
        for (auto i : nums) {
            last += i;
            st = max(st, i);
        }

        function<int(int, int, int)> dfs = [&](int node, int par, int sum) {
            int cursum = nums[node];
            for (auto it : adj[node]) {
                if (it != par) {
                    cursum += dfs(it, node, sum);
                }
            }
            if (cursum == sum) {
                return 0;  // Reset this subtree
            }
            return cursum;  // Propagate current sum upwards
        };

        for (int i = st; i<=last; i++) {
            if (last % i == 0) {
                int comp = last / i;
                if (dfs(0, -1, i) == 0) {
                    return comp - 1;
                }
            }
        }

        return -1;  // No valid division found
    }
};
