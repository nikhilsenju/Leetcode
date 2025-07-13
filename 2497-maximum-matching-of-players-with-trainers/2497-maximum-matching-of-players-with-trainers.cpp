class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int n = p.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        int ans = 0 ;
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        while(i<n && j<m){
            if(p[i]<=t[j]){
                i++;
                j++;
                ans++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};