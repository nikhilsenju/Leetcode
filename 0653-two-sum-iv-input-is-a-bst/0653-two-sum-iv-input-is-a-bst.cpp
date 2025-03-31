class Solution {
public:
    stack<TreeNode *> stn;  // Stack for in-order traversal (smallest value)
    stack<TreeNode *> stb;  // Stack for reverse in-order traversal (largest value)

    int next() {
        TreeNode *root = stn.top();
        stn.pop();
        int ans = root->val;

        if (root->right) {
            root = root->right;
            while (root) {
                stn.push(root);
                root = root->left;
            }
        }
        return ans;
    }

    int before() {
        TreeNode *root = stb.top();
        stb.pop();
        int ans = root->val;

        if (root->left) {
            root = root->left;
            while (root) {
                stb.push(root);
                root = root->right;
            }
        }
        return ans;
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        TreeNode *Node1 = root;
        TreeNode *Node2 = root;

        // Fill the stacks
        while (Node1) {
            stn.push(Node1);
            Node1 = Node1->left;
        }
        while (Node2) {
            stb.push(Node2);
            Node2 = Node2->right;
        }

        int left = next();
        int right = before();

        while (left < right) {
            if (left + right == k) {
                return true;
            } else if (left + right < k) {
                if (!stn.empty()) left = next();
                else return false;
            } else {
                if (!stb.empty()) right = before();
                else return false;
            }
        }
        return false;
    }
};
