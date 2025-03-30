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

    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lf = findleftheight(root);
        int rg = findrightheight(root);

        if(lf==rg){
            return (1<<lf)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int findleftheight(TreeNode *root){
        int h = 0;
        while(root){
            h++;
            root=root->left;
        }
        return h;
    }
    int findrightheight(TreeNode *root){
        int h = 0;
        while(root){
            h++;
            root=root->right;
        }
        return h;

    }
};