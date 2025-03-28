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
    map<int,map<int,multiset<int>>>mp;
    void dfs(TreeNode *root,int i,int j){
        if(!root){
            return;
        }
        dfs(root->left,i+1,j-1);
        mp[j][i].insert(root->val);
        dfs(root->right,i+1,j+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>> ans;
        for(auto i:mp){
            vector<int> tmp;
            for(auto j:i.second){
                for(auto k:j.second){
                    tmp.push_back(k);
                }
            }
            ans.push_back(tmp);
        }
        return ans;

    }
};