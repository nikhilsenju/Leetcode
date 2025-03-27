/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi=-1e9;
    int sum(TreeNode * root){
        if(!root){
            return 0;
        }
        int lf = sum(root->left);
        int rg = sum(root->right);
        lf = max(0,lf);
        rg = max(0,rg);
        maxi = max(maxi,root->val+rg+lf);
        return root->val+max(lf,rg);

    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return maxi;

        
    }
};