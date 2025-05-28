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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
        long long maxi = 0;
        while(!q.empty()){
            long long sz = q.size();
            long long lf = q.front().second;
            long long left = 0;
            long long right = 0;
            for(int i=0;i<sz;i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                long long val = it.second-lf;
                if(i==0){
                    left=val;
                }
                if(i==sz-1){
                    right = val;
                }
                if(node->left){
                    q.push({node->left,2*val});
                }
                if(node->right){
                    q.push({node->right,2*val+1});
                }
            }
            cout<<lf<<" "<<right<<endl;
            maxi = max(maxi,right-left+1);
        }
        return maxi;

    }
};