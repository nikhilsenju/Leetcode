class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int left = 0;
        int right = m-1;
        while(right>=left){
            int mid = (right+left)/2;
            int maxrow = -1;
            int maxi = -1;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi = mat[i][mid];
                    maxrow = i;
                }
            }
            int leftval = (mid==0?-1:mat[maxrow][mid-1]);
            int rightval = (mid==m-1?-1:mat[maxrow][mid+1]);
            if(mat[maxrow][mid]>leftval && mat[maxrow][mid]>rightval){
                return {maxrow,mid};
            }
            else if(mat[maxrow][mid]<leftval){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return {-1,-1};
        
    }
};