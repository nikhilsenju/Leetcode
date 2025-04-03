class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>&vp) {
        v.push_back({vp[0],vp[1]});
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        int i=0;
        int j=0;
        int n = v.size();
        while(i<n && j<n){
            j=i+1;
            int start=v[i][0];
            int maxend = v[i][1];
            while(j<n && maxend>=v[j][0]){
                maxend=max(maxend,v[j][1]);
                j++;
            }
            ans.push_back({start,maxend});
            i=j;
        }
        return ans;
    }
};