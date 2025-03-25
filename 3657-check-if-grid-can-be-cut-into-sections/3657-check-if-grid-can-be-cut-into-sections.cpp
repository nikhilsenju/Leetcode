class Solution {
public:
    bool solve(vector<pair<int,int>>&vp){
        int n = vp.size();
        int st = vp[0].first;
        int end = vp[0].second;
        int c=0;
        for(int i=1;i<n;i++){
            int curst = vp[i].first;
            int curend = vp[i].second;
            if(curst>=end){
                c++;
            }
            end = max(end,curend);
        }
        return c>=2;


    }
    bool checkValidCuts(int n, vector<vector<int>>& v) {
        vector<pair<int,int>> y;
        vector<pair<int,int>> x;
        for(auto i:v){
            y.push_back({i[1],i[3]});
            x.push_back({i[0],i[2]});
        }
        sort(y.begin(),y.end());
        sort(x.begin(),x.end());
        return (solve(y)||solve(x));

        

        
    }
};