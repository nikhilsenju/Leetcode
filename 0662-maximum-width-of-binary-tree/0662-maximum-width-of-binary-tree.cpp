/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
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
        long long maxi = 0;
        queue<pair<TreeNode*,long long>>pq;
        pq.push({root,1});
        while(!pq.empty()){
            long long sz = pq.size();
            long long l = INT_MAX;
            long long r = INT_MIN;
            long long mmin = pq.front().second;
            for(long long j=0;j<sz;j++){
                auto it = pq.front();
                pq.pop();
                TreeNode * cur = it.first;
                long long val = it.second-mmin;
                if(cur){
                    l = min(l,val);
                    r = max(r,val);
                    if(cur->left){
                        pq.push({cur->left,2*val});
                    }
                    if(cur->right){
                        pq.push({cur->right,2*val+1});
                    }
                }
            }
            if(r>=l){
                maxi = max(maxi,r-l+1);
            }
        }
        return maxi;
        
    }
};