class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int r = m-1;
        int u = 0;
        int d = n-1;
        vector<int> ans;
        while(u<=d && r>=l){
            if(u>d || r<l){
                break;
            }
            for(int i=l;i<=r;i++){
                ans.push_back(mat[u][i]);
            }
            if(u>d || r<l){
                break;
            }
            u++;
            for(int i=u;i<=d;i++){
                ans.push_back(mat[i][r]);
            }
            if(u>d || r<l){
                break;
            }
            r--;
            for(int i=r;i>=l;i--){
                ans.push_back(mat[d][i]);
            }
            if(u>d || r<l){
                break;
            }
            d--;
            for(int i=d;i>=u;i--){
                ans.push_back(mat[i][l]);
            }
            if(u>d || r<l){
                break;
            }
            l++;
        }
        return ans;
        
    }
};