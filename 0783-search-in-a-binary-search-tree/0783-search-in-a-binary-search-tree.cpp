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
    TreeNode * dfs(TreeNode * root,int tar){
        if(!root){
            return NULL;
        }
        if(root->val==tar){
            return root;
        }
        if(root->val<tar){
           return dfs(root->right,tar);
        }
        else{
            return dfs(root->left,tar);
        }
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root,val);
    }
};