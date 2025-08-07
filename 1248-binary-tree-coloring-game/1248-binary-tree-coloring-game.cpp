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
    int N = 105;
    vector<vector<int>>adj;
    vector<int> vis;
    void bfs(TreeNode * root){
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it->left){
                adj[it->left->val].push_back(it->val);
                adj[it->val].push_back(it->left->val);
                q.push(it->left);
            }
            if(it->right){
                adj[it->right->val].push_back(it->val);
                adj[it->val].push_back(it->right->val);
                q.push(it->right);
            }
        }
    }
    int count(int node){
        int cnt = 1;
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                cnt+=count(i);
            }
        }
        return cnt;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        adj.assign(n+1,{});
        vis.assign(n+1,0);
        bfs(root);
        vis[x]=1;
        int left = 0;
        int right = 0;
        for(auto i:adj[x]){
            if(left ==0){
                left = count(i);
            }
            else{
                right = count(i);
            }
        }
        int par  = n-(left+right+1);
        if(max({par,left,right})>n/2){
            return true;
        }
        return false;



    }
};