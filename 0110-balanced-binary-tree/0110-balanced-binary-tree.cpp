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
    int maxDepth(TreeNode * root){
        if(!root){
            return 0;
        }
        int lf = maxDepth(root->left);
        int rg = maxDepth(root->right);
        if(lf==-1 || rg==-1){
            return -1;
        }
        if(abs(lf-rg)>1){
            return -1;
        }
        return max(lf,rg)+1;
    }
    bool isBalanced(TreeNode* root) {
        int maxi = maxDepth(root);
        return maxi==-1?false:true;
        
    }
};