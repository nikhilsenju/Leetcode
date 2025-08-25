class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        int fl = 1;
        for(int i=0;i<m;i++){
            int tmpi = 0;
            int tmpj = i;
            vector<int>tmp;
            while(tmpi<n && tmpj>=0){
                tmp.push_back(mat[tmpi][tmpj]);
                tmpi++;
                tmpj--;
            }
            if(!fl){
                for(auto j:tmp){
                    ans.push_back(j);
                }
            }
            else{
                for(int j=tmp.size()-1;j>=0;j--){
                    ans.push_back(tmp[j]);
                }
            }
            fl=!fl;
        }
         for(int i=1;i<n;i++){
            int tmpi = i;
            int tmpj = m-1;
            vector<int>tmp;
            while(tmpi<n && tmpj>=0){
                tmp.push_back(mat[tmpi][tmpj]);
                tmpi++;
                tmpj--;
            }
            if(!fl){
                for(auto j:tmp){
                    ans.push_back(j);
                }
            }
            else{
                for(int j=tmp.size()-1;j>=0;j--){
                    ans.push_back(tmp[j]);
                }
            }
            fl=!fl;
        }
        return ans;
    }
};