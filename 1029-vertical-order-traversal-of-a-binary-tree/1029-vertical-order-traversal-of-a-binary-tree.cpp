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
    void dfs(TreeNode * root, int left,int top,map<int,map<int,multiset<int>>>&mp){
        if(!root){
            return;
        }
        mp[left][top].insert(root->val);
        dfs(root->left,left-1,top+1,mp);
        dfs(root->right,left+1,top+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        dfs(root,0,0,mp);
        vector<vector<int>> vp;
        for(auto i:mp){
            vector<int> tmp;
            for(auto j:i.second){
                for(auto k:j.second){
                    tmp.push_back(k);
                }
            }
            vp.push_back(tmp);
        }
        return vp;
    }
};