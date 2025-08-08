class Solution {
public:
    long long dfs(int node, int par, long long val, vector<vector<int>>& adj, vector<int>& nums) {
        long long sum = 0;
        for (auto i : adj[node]) {
            if (i != par) {
                long long ch = dfs(i, node, val, adj, nums);
                if (ch == LLONG_MAX) return LLONG_MAX;
                sum += ch;
            }
        }
        sum += nums[node];
        if (sum == val) return 0;
        if (sum > val) return LLONG_MAX;
        return sum;
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long st = *max_element(nums.begin(), nums.end());
        long long end = accumulate(nums.begin(), nums.end(), 0LL);

        for (long long ele = st; ele <= end; ele++) {
            if (end % ele == 0) {
                if (dfs(0, -1, ele, adj, nums) == 0) {
                    long long comp = end / ele;
                    return comp - 1;
                }
            }
        }
        return -1;
    }
};
