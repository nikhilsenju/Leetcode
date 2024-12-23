class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> curr;

            // Extract current level nodes
            while (sz--) {
                auto node = q.front();
                q.pop();
                curr.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Map to store original indices
            vector<pair<int, int>> arr;
            for (int i = 0; i < curr.size(); i++) {
                arr.push_back({curr[i], i});
            }

            // Sort the array based on values
            sort(arr.begin(), arr.end());

            // Count the number of swaps needed to sort
            vector<bool> visited(curr.size(), false);
            for (int i = 0; i < arr.size(); i++) {
                // If already visited or in correct position
                if (visited[i] || arr[i].second == i) continue;

                // Count the size of the cycle
                int cycle_size = 0, j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = arr[j].second;
                    cycle_size++;
                }

                // If there's a cycle, add (cycle_size - 1) swaps
                if (cycle_size > 1) {
                    ans += (cycle_size - 1);
                }
            }
        }

        return ans;
    }
};
