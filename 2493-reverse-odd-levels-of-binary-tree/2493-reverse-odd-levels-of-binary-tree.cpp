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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        //bfs//
        queue<TreeNode *> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            vector<TreeNode *> curlevel;
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                curlevel.push_back(node);
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
            }
            if(level&1){
                int i = 0;
                int j = curlevel.size()-1;
                while(j>i){
                    swap(curlevel[i]->val,curlevel[j]->val);
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};