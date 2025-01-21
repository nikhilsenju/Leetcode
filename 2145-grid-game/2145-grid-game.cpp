typedef long long ll;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        int n = grid[0].size();
        ll pre1=0;
        ll suff1=0;
        ll pre2=0;
        ll suff2=0;
        ll ans=1e18;
        for(int i=0;i<n;i++){
            suff1+=grid[0][i];
            suff2+=grid[1][i];
            
        }
        for(int i=0;i<n;i++){
            pre1+=grid[0][i];
            ans=min(ans,max(suff1-pre1,pre2));
            pre2+=grid[1][i];

        }
        return ans;

        
        
    }
};