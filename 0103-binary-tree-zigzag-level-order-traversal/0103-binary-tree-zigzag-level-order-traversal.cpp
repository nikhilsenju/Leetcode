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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        int fl = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int> tmp;
            for(int j=0;j<sz;j++){
                auto cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            if(fl){
                reverse(tmp.begin(),tmp.end());
            }
            ans.push_back(tmp);
            fl=!fl;
        }
        return ans;
        
    }
};