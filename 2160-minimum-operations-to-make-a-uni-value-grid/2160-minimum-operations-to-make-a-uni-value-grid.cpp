class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v;
        int fl=0;
        set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                st.insert(grid[i][j]%x);
                v.push_back(grid[i][j]);
            }
        }
        if(st.size()!=1){
            return -1;
        }
        sort(v.begin(),v.end());
        int num = v[v.size()/2];
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=(abs(grid[i][j]-num)/x);
            }
        }
        return ans;


        
        
    }
};