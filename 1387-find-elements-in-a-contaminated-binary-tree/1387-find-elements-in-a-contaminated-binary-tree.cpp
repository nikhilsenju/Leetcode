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
class FindElements {
public:
    map<int,int>mp;
    void f(TreeNode * root,int cur){
        if(root==NULL){
            return;
        }
        root->val = cur;
        mp[cur]++;
        if(root->left){
            f(root->left,cur*2+1);
        }
        if(root->right){
            f(root->right,cur*2+2);
        }
    }
    FindElements(TreeNode* root) {
        f(root,0);
    }
    
    bool find(int target) {
        if(mp[target]){
            return true;
        }
        return false;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */