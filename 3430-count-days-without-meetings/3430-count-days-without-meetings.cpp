class Solution {
public:
    int countDays(int days, vector<vector<int>>& v) {
        vector<pair<int,int>> vp;
        for(auto i:v){
            vp.push_back({i[0],i[1]});
        }
        sort(vp.begin(),vp.end());
        // int ans = days;
        int st = vp[0].first;
        int end = vp[0].second;
        int n =vp.size();
        vector<pair<int,int>> ans;
        for(int i=1;i<n;i++){
            int nst = vp[i].first;
            int nsend = vp[i].second;
            if(nst>end){
                ans.push_back({st,end});
                st = nst;
                end = nsend;
            }
            else{
                end = max(end,nsend);
            }

        }
        ans.push_back({st,end});
        for(auto i:ans){
            days-=(i.second-i.first+1);
        }
        return days;

        
    }
};