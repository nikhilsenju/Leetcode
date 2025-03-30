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
    map<int,int> mp;
    TreeNode * solve(int pl,int pr , vector<int>&pre,int il,int ir,vector<int>&ino){
        if(il>ir){
            return NULL;
        }
        TreeNode * root = new TreeNode(pre[pl]);
        int idx = mp[pre[pl]];
        int lf = idx-il;
        int rg = ino.size()-idx-1;
        root->left = solve(pl+1,pl+lf,pre,il,idx-1,ino);
        root->right = solve(pl+lf+1,pr,pre,idx+1,ir,ino);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode * root = solve(0,preorder.size()-1,preorder,0,inorder.size()-1,inorder);
        return root;
    }
};