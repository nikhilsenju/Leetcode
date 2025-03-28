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
    void dfs(TreeNode * root,int j){
        if(!root){
            return;
        }
        if(mp.find(j)==mp.end()){
            mp[j]=root->val;
        }
        dfs(root->right,j+1);
        dfs(root->left,j+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        vector<int> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;

        
    }
};