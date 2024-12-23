class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> curr;

            // Extract current level nodes
            while (sz--) {
                auto node = q.front();
                q.pop();
                curr.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            map<int,int> mp;
            for(int i=0;i<curr.size();i++){
                mp[curr[i]]=i;
            }
            vector<int> tar = curr;
            sort(tar.begin(),tar.end());
            for(int i=0;i<tar.size();i++){
                if(mp[tar[i]]!=i){
                    ans++;
                    int x = mp[tar[i]];
                    int y = mp[curr[i]];
                    mp[tar[i]]=y;
                    mp[curr[i]]=x;
                    swap(curr[x],curr[y]);
                }


            }
        }

        return ans;
    }
};
